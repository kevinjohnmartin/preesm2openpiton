//File edited by soys - Shame of you sniper - 18.March.2021
/**
 * @file Core3.c
 * @generated by InstrumentedCPrinter
 * @date Thu Mar 18 19:00:00 CET 2021
 *
 * Code generated for processing element Core3 (ID=3).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Split_0_output__Sobe__9;  // explode_Split_0_output > Sobel_9 size:= 9856*char defined in Core0
extern uchar *const output_9__input__0;  // explode_Split_0_output_output_9 > Sobel_9_input size:= 9856*uchar defined in Core0
extern uchar *const output__y_9__0;  // Erosion_9_output > implode_display_0_y_y_9 size:= 6336*uchar defined in Core0
extern char *const Erosion_9__implode_display_0__0;  // Erosion_9 > implode_display_0_y size:= 6336*char defined in Core0
extern uint64_t dumpedTimes[189]; //  size:= 189*uint64_t
extern int nbExec[189]; //  size:= 189*int

// Core Global Definitions
char Core3[16896]; //  size:= 16896*char
char *const Sobel_9__Dilation_9__0 = (char*) (Core3+0);  // Sobel_9 > Dilation_9 size:= 9152*char
char *const Dilation_9__Erosion_9__0 = (char*) (Core3+9152);  // Dilation_9 > Erosion_9 size:= 7744*char
uchar *const output__input__18 = (uchar*) (Core3+0);  // Sobel_9_output > Dilation_9_input size:= 9152*uchar
uchar *const output__input__19 = (uchar*) (Core3+9152);  // Dilation_9_output > Erosion_9_input size:= 7744*uchar
int idx;

void *computationThread_Core3(void *arg){
	unsigned int my_time;
	if (arg != NULL) {
		printf("Warning: expecting NULL arguments\n");
	}
	// Begin the execution loop
#ifdef LOOP_SIZE // Case of a finite loop
	int index;
	for(index=0;index<LOOP_SIZE;index++){
#else // Default case of an infinite loop
	while(1){
#endif
		if (index > 0){
			my_time = stopTiming(0);
			printf("Loop overhead %d us\n", my_time);
		}
		startTiming(0);
		while(lock(3));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		dumpTime(85/*globalID*/,dumpedTimes); // 
		*(nbExec+86) = 0;
		receiveStart(); // Core0 > Core3: explode_Split_0_output__Sobe__9
		dumpTime(86/*globalID*/,dumpedTimes); // 
		*(nbExec+87) = 0;
		receiveEnd(0, 3); // Core0 > Core3: explode_Split_0_output__Sobe__9
		dumpTime(87/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+88); idx++){
			sobel(352/*width*/,28/*height*/,output_9__input__0,output__input__18); // Sobel_9
		}
		dumpTime(88/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+89); idx++){
			dilation(26/*height*/,352/*width*/,2/*window*/,output__input__18,output__input__19); // Dilation_9
		}
		dumpTime(89/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+90); idx++){
			erosion(22/*height*/,352/*width*/,2/*window*/,output__input__19,output__y_9__0); // Erosion_9
		}
		dumpTime(90/*globalID*/,dumpedTimes); // 
		*(nbExec+91) = 0;
		sendStart(3, 0); // Core3 > Core0: Erosion_9__implode_display_0__0
		dumpTime(91/*globalID*/,dumpedTimes); // 
		*(nbExec+92) = 0;
		sendEnd(); // Core3 > Core0: Erosion_9__implode_display_0__0
		dumpTime(92/*globalID*/,dumpedTimes); // 
		while(lock(3));
//		pthread_barrier_wait(&iter_barrier);
	}
	my_time = stopTiming(0);
	printf("Loop overhead %d us\n", my_time);
	return NULL;
}

