#!/usr/bin/env python
import os
import sys
import time
import subprocess
from shutil import copyfile
from datetime import date
import ntpath
import re

SOURCE_PATH=piton_root = os.environ['PITON_ROOT']+"/utils"

def set_brackets(my_str, brackets_count):
    opening = 0
    closing = 0
    for element in range(0, len(my_str)):
        el = my_str[element]
        if el == '{':
            opening = opening + 1
        elif el == '}':
            closing = closing + 1
    brackets_count = brackets_count + opening - closing
    print brackets_count
    return brackets_count

def main():
    sys.dont_write_bytecode = True #Stop to generate .pyc files
    #https://patorjk.com/software/taag/#p=display&f=Big&t=CoW%20Automatic%20Script
    #Font: big
    print """
        
  _____                                    __      ____                   _____ _ _              
 |  __ \                                   \ \    / __ \                 |  __ (_) |             
 | |__) | __ ___  ___  ___ _ __ ___    _____\ \  | |  | |_ __   ___ _ __ | |__) || |_ ___  _ __  
 |  ___/ '__/ _ \/ _ \/ __| '_ ` _ \  |_____ > > | |  | | '_ \ / _ \ '_ \|  ___/ | __/ _ \| '_ \ 
 | |   | | |  __/  __/\__ \ | | | | |       / /  | |__| | |_) |  __/ | | | |   | | || (_) | | | |
 |_|   |_|  \___|\___||___/_| |_| |_|      /_/    \____/| .__/ \___|_| |_|_|   |_|\__\___/|_| |_|
                                                        | |                                      
                                                        |_|                                      
       __   ___  
      /_ | / _ \ 
 __   _| || | | |
 \ \ / / || | | |
  \ V /| || |_| |
   \_/ |_(_)___/ 
                       
    """
    time.sleep(1)
    try:
        PREESM_PATH = sys.argv[1] #-ntm: apply ntm, -cow: apply cow to run in local machine, -cowsniper: apply cow to run in sniper simulator 
    except:
        sys.exit("\nYou must inform as 1st argument the root directory of the Preesm application where the Code/ dir is located, for example: preesm2openpiton ~/preesm_apps/sorting/Code \n")
    try:
        OPEN_PITON_PATH = sys.argv[2] #-ntm: apply ntm, -cow: apply cow to run in local machine, -cowsniper: apply cow to run in sniper simulator 
    except:
        sys.exit("\nYou must inform as 2nd argument the directory of to deploy the OpenPiton version of the app, for example: preesm2openpiton <preesm_app_path> ~/openpiton_apps/sorting/ \n")

    PREESM_PATH     = os.path.abspath(PREESM_PATH)
    OPEN_PITON_PATH = os.path.abspath(OPEN_PITON_PATH)

    GENERATED_PATH  = PREESM_PATH+"/Code/generated/"
    SRC_PATH        = PREESM_PATH+"/Code/src/"
    INC_PATH        = PREESM_PATH+"/Code/include/"

    #--------------- GENERATE THE CORE FILE LIST -----------------------------
    core_files_list = []    
    for file in os.listdir(GENERATED_PATH):
        if file.endswith(".c") and "Core" in file and "Sniper" not in file:
            core_files_list.append(os.path.join(GENERATED_PATH, file))

    if not core_files_list:
        sys.exit("\nNone Core file found in: "+GENERATED_PATH+"\n")

    NUMBER_OF_CORES = len(core_files_list)
    
    #--------------- GENERATE THE PREESM_INCLUDE FILE ------------------------
    src_files_list = []    
    for file in os.listdir(SRC_PATH):
        if file.endswith(".c") and not "clock.c" in file: #Igonres clock.c
            src_files_list.append(os.path.join(SRC_PATH, file))

    if not src_files_list:
        sys.exit("\nNone Core file found in: "+SRC_PATH+"\n")
    

    #Test patters to detects a function declaration in C
    test_list = ['int', 'void', 'string', 'double', 'float', 'char']
    test_list2 = ['(']
    test_list3 = [';', '=']

    src_functions = []
    #Read all .c files of SRC folder, extract the C functions and put to a list src_functions
    for src_path in src_files_list:

        src_name = ntpath.basename(src_path)
        print "\nReading "+str(src_name)+" ..."
        new_lines = []

        with open(src_path) as fp:
            original_lines = fp.readlines()
            #original_lines = fp.read()
            #teste =  re.findall(r'(?<=(?<=int\s)|(?<=void\s)|(?<=string\s)|(?<=double\s)|(?<=float\s)|(?<=char\s)).*?(?=\s?\()', str(original_lines))
            
            copy_function_mode = False
            for line in original_lines:
                
                stripped_line = line.strip()

                begin_new_function = not stripped_line.startswith("//") and any(line.startswith(ele) for ele in test_list) and any(ele in line for ele in test_list2) and any(ele not in line for ele in test_list3)
            
                #Test to detects a function in C
                if copy_function_mode == False and begin_new_function == True:
                    copy_function_mode = True
                    #brackets_count = 0
                    #brackets_count = set_brackets(stripped_line, brackets_count)

                    new_lines.append("\n"+line)

                elif copy_function_mode == True:

                    #if not stripped_line.startswith("//"):
                    #    brackets_count = set_brackets(stripped_line, brackets_count)
                    #if brackets_count == 0:
                    #    copy_function_mode = False

                    new_lines.append(line)
                    
            #Wrintes to the file
            functions_lines = ""
            for line in new_lines:
                functions_lines = functions_lines + line
            
            #print functions_lines
            src_functions.append([src_name, functions_lines])




    new_include_path = OPEN_PITON_PATH+"/preesm_defines.h"
    copyfile(SOURCE_PATH+"/preesm2openpiton/preesm_defines.h", new_include_path )

    #Define NB_CORES and PREESM_LOOP_SIZE
    sed_cmd = "sed -i \"s|#define PREESM_LOOP_SIZE|#define PREESM_LOOP_SIZE\t3|g\" "+new_include_path
    os.system(sed_cmd)
    sed_cmd = "sed -i \"s|#define LOOP_SIZE|#define LOOP_SIZE\t\tPREESM_LOOP_SIZE //Compatibility issue|g\" "+new_include_path
    os.system(sed_cmd)
    sed_cmd = "sed -i \"s|#define NB_CORES|#define NB_CORES\t\t"+str(NUMBER_OF_CORES)+"|g\" "+new_include_path
    os.system(sed_cmd)

    for element in src_functions:
        #print "Function for: "+element[0]
        #print element[1]

        final_string = "\n //********************** "+element[0].upper()+ " **********************\n" + element[1]

        file = open(new_include_path, 'a')
        file.write(final_string)
        file.close() 

    file = open(new_include_path, 'a')
    file.write("\n#endif")
    file.close() 

    #--------------- GENERATE THE MAIN FILE ------------------------

    global_variables = ""
    cores_functions = ""

    core_files_list.sort()
    for core_path in core_files_list:
        
        core_id = int(core_path.split("Core")[1][:-2])
        core_name = "Core"+str(core_id)
        print "\nReading Core "+core_name+"..."
        new_lines = []

        global_variables = global_variables + "//********** "+core_name+" global definitions *****************\n"
        cores_functions = cores_functions + "//********** "+core_name+" thread function *****************\n"

        copy_global_vars_enabled = False
        copy_function_enabled = False

        with open(core_path) as fp:
            original_lines = fp.readlines()
            for line in original_lines:
                stripped_line = line.strip()

                if copy_function_enabled == True:
                    cores_functions = cores_functions + line
                
                elif copy_global_vars_enabled == False:
                    if "// Core Global Definitions" in line:
                        copy_global_vars_enabled = True

                else:
                    begin_new_function = not stripped_line.startswith("//") and any(line.startswith(ele) for ele in test_list) and any(ele in line for ele in test_list2) and any(ele not in line for ele in test_list3)
                    if begin_new_function and "computationThread_"+core_name in line:
                        copy_global_vars_enabled = False
                        copy_function_enabled = True
                        cores_functions = cores_functions + line
                    else:
                        global_variables = global_variables + line


    new_main_path = OPEN_PITON_PATH+"/preesm_main.c"
    copyfile(SOURCE_PATH+"/preesm2openpiton/main.c", new_main_path )

    final_lines = ""
    main_lines = ""
    
    replace_list = []

    with open(new_main_path) as fp:
        original_lines = fp.readlines()
        copy_enabled = True
        for line in original_lines:
            
            if copy_enabled:
                final_lines = final_lines + line
            else:
                main_lines = main_lines + line
                if "//Thread selection" in line:
                    main_lines = main_lines + "    switch(core_id){\n"
                    
                    for core_path in core_files_list:
                        core_id = int(core_path.split("Core")[1][:-2])
                        core_function_name = "computationThread_Core"+str(core_id)
                        
                        replace_old = "*computationThread_Core"+str(core_id)+"(void *arg)"
                        replace_new = core_function_name+"(void *arg)"
                        replace_list.append([replace_old, replace_new])


                        main_lines = main_lines + "        case "+str(core_id)+":\n"
                        main_lines = main_lines + "            "+core_function_name+"();\n"
                        main_lines = main_lines + "            break;\n"
                        
                        
                    main_lines = main_lines + "        default:\n"
                    main_lines = main_lines + "            printf(\"ERROR, unknown core_id = %d\\n\", core_id);\n"
                    main_lines = main_lines + "    }\n"


            if "//Core Global Definitions" in line:
                final_lines = final_lines + global_variables

            if "//Core functions" in line: 
                final_lines = final_lines + cores_functions
                copy_enabled = False

            
    final_lines = final_lines + main_lines

    #Final adjustments
    final_lines = final_lines.replace('2 is number of threads', str(NUMBER_OF_CORES)+" is number of threads")
    final_lines = final_lines.replace("pthread_barrier_wait(", "barrier_wait(")


    for replace_el in replace_list:
        final_lines = final_lines.replace(replace_el[0], replace_el[1])

    file = open(new_main_path, 'w')
    file.write(final_lines)
    file.close()  
    
    print 
    print "New files build at: "+OPEN_PITON_PATH+":"
    print "   - "+ntpath.basename(new_include_path)
    print "   - "+ntpath.basename(new_main_path)

    print
    print "Script preesm2openpiton concluded!"



#Call of function main, this approaches enables to call a function before it declaration
main()