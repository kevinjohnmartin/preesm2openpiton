# Preesm to OpenPiton
Project with the tutorial and code related to the conversion of Preesm generated application to run in OpenPiton

**Author**: Marcelo Ruaro, Kevin Martin


# Tutorial: How to Convert Preesm Apps. to OpenPiton

The tutorial was recorder in a form of a video available at YouTube in the link below:

### **Video**: Step-by-step conversio of a Preesm 3.4 application to OpenPiton: 
[![IMAGE ALT TEXT HERE](git_utils/image_video_tutorial.jpeg)](https://youtu.be/EJrUHW0lMUQ) 

## Disclaimer
This repository already has four application from Preesm repository converted to OpenPiton and that are running on it. 
* Stereo
* Stabilization
* Sobel
* SynParallel (used in the video tutorial above)

You can use them and go directly to Step 3 and after to Step 6. Note that they were generated to 4 cores. To generate to a different core number you must start from Step 1, but you can reuse the same *.h* file (explained bellow), since it file is agnostic to the number of cores. Your mission is to generate a new *.c* file with the *preesm2openpiton* script and fix the bugs associated to this file only, since the .h will be reused and was already validated.

## Step 1: Application development on Preesm
The Preesm used in this tutorial was in version 3.4. First, you must develop your application on Preesm and generate it using any Preesm's workflow.

## Step 2: Call *preesm2openpiton* script
The *preesm2openpiton* script available [here](https://github.com/Nooman-LabSTICC/nooman-openpiton/blob/master/bin/preesm2openpiton), can convert partially your Preesm application to a form that is amost executable in Openpition.

Note that the script doesn't do everything so it is necessary to manually modify the code to remove the compilation errors to run in Openpiton.

## Step 3: Pass the generated files to Openpiton directory

The *preesm2openpiton* script will generate two files:
* **preesm_defines.h**
  * Contains:
    1. The implementation of the functions of each actor
    2. The definition of structures
    3. Another important definitions and includes
* **preesm_main.c**
  * Contains:
    1. The declaration of the shared variables
    2. The implementation of the Preesm generated functions that represent the code of each threads: *computationThread_Core..*
    3. The **main** function, which detects the core id of the running core and call the respective function. This procedure represents the execution of the threads, assigning to each core its respective thread execution, which is a call for the function *computationThread_Core..*

These two files need to be copied to Openpiton directory which holds the software codes.
* **preesm_defines.h**: must be copied to *nooman-openpiton/piton/verif/diag/assembly/include/riscv/ariane/*
  * Note that maybe (I never tried) this file can be pasted on the same directory of *preesm_main.c* below.
* **preesm_main.c**: must be copied to *nooman-openpiton/piton/verif/diag/c/riscv/ariane/*

> You can rename this two files above freerly. I recomend to rename to the name of your application and the number of cores, for instance: *stereo_4cores.c* and *stereo_4cores.h*. 

## Step 4: Call the *openpiton* script to generate the HW and compile the SW

The next step is to go to the openpiton build directory: *nooman-openpiton/build* and call the script to generate the HW and compile the sofware. More details about this script are available [here](https://github.com/Nooman-LabSTICC/nooman-openpiton/blob/master/bin/preesm2openpiton). For now, we will use as example a system with 4 cores simulated using Verilator.

> openpiton 2 2 -V -all preesm_main

Observe that the **2 2** represents the many-core XY dimension, respectively, in number of cores (two cores at X-dimension and 2 cores at Y-dimension). The **-V** flag use Verilator to compile and simulate the HW. The **-all** indicates to the script that it must generate the HW **and** compile/run the software. The **-all** is used only at first time, after generating the HW you can only use the **-run** to compile and execute the application. Finally, the **preesm_main** indicates the name of the .c file generated by Preesm. If you rename this file don't forget to use the same name when calling the openpiton script.



## Step 5: Fix the compilation errors
The execution of the openpiton command above probably will generate compilation errors pointing either to your .h or .c file. Your role is to identify such errors and try to solve them changing both files. 

Most of the errors are due to structures definition not found, variables not found, and functions that your application may use that are not supported by Openpiton as the malloc, free, and others. Is not a easy job, so you have to decide, for instance, in the case of malloc, to adapt your application to use static memory allocation, or implement yourself a simple malloc function that uses a predefined memory area. 

Other erros also can occurs when including some libraries as math.h. One tip is to play with diferent GCC and Linker flags during SW compilation. You can change this flags on the file: *nooman-openpiton/piton/tools/bin/rv64_cc*.

> Remember, during the compilation errors fixing phase, you don't need to set **-all** flag again in openpiton script. This will generate and recompile the HW which takes time. Instead, just use the **-run** flag as the example below:
> * openpiton 2 2 -V **-run** preesm_main

## Step 6: Debug your application and evaluate its memory and energy profile

Once the compilation can proceed sucessifully, the simulation will start and you can open the ManyGUI to debug your application and evaluate its memory and energy profile. To do so, please recompile your application using the following command:

> * openpiton 2 2 -V **-run** preesm_main **-debug**

The **-debug** flag will open the ManyGUI automatically. The video in the top of this page includes the explanation of how to use ManyGUI. You can see more details of ManyGUI tool [here](https://github.com/Nooman-LabSTICC/manyGUI). Specifically, you will find two videos on this link, describing how to use the tool. For convenience, the same videos are listed below:
### Video tutorials for ManyGUI:

### Version 1: 
[Watch on YouTube](https://youtu.be/XOHMqZNIwks)
### Version 2:
[Watch on YouTube](https://youtu.be/VU6yRrICwsk)