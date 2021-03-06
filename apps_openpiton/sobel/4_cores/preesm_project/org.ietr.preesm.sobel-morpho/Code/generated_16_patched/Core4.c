//File edited by soys - Shame of you sniper - 18.March.2021
/**
 * @file Core4.c
 * @generated by InstrumentedCPrinter
 * @date Thu Mar 18 19:00:00 CET 2021
 *
 * Code generated for processing element Core4 (ID=4).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Split_0_output__Sobe__10;  // explode_Split_0_output > Sobel_10 size:= 9856*char defined in Core0
extern uchar *const output_10__input__0;  // explode_Split_0_output_output_10 > Sobel_10_input size:= 9856*uchar defined in Core0
extern uchar *const output__y_10__0;  // Erosion_10_output > implode_display_0_y_y_10 size:= 6336*uchar defined in Core0
extern char *const Erosion_10__implode_display___0;  // Erosion_10 > implode_display_0_y size:= 6336*char defined in Core0
extern uint64_t dumpedTimes[189]; //  size:= 189*uint64_t
extern int nbExec[189]; //  size:= 189*int

// Core Global Definitions
char Core4[16896]; //  size:= 16896*char
char *const Sobel_10__Dilation_10__0 = (char*) (Core4+0);  // Sobel_10 > Dilation_10 size:= 9152*char
char *const Dilation_10__Erosion_10__0 = (char*) (Core4+9152);  // Dilation_10 > Erosion_10 size:= 7744*char
uchar *const output__input__20 = (uchar*) (Core4+0);  // Sobel_10_output > Dilation_10_input size:= 9152*uchar
uchar *const output__input__21 = (uchar*) (Core4+9152);  // Dilation_10_output > Erosion_10_input size:= 7744*uchar
int idx;

void *computationThread_Core4(void *arg){
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
		while(lock(4));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		dumpTime(93/*globalID*/,dumpedTimes); // 
		*(nbExec+94) = 0;
		receiveStart(); // Core0 > Core4: explode_Split_0_output__Sobe__10
		dumpTime(94/*globalID*/,dumpedTimes); // 
		*(nbExec+95) = 0;
		receiveEnd(0, 4); // Core0 > Core4: explode_Split_0_output__Sobe__10
		dumpTime(95/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+96); idx++){
			sobel(352/*width*/,28/*height*/,output_10__input__0,output__input__20); // Sobel_10
		}
		dumpTime(96/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+97); idx++){
			dilation(26/*height*/,352/*width*/,2/*window*/,output__input__20,output__input__21); // Dilation_10
		}
		dumpTime(97/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+98); idx++){
			erosion(22/*height*/,352/*width*/,2/*window*/,output__input__21,output__y_10__0); // Erosion_10
		}
		dumpTime(98/*globalID*/,dumpedTimes); // 
		*(nbExec+99) = 0;
		sendStart(4, 0); // Core4 > Core0: Erosion_10__implode_display___0
		dumpTime(99/*globalID*/,dumpedTimes); // 
		*(nbExec+100) = 0;
		sendEnd(); // Core4 > Core0: Erosion_10__implode_display___0
		dumpTime(100/*globalID*/,dumpedTimes); // 
		while(lock(4));
//		pthread_barrier_wait(&iter_barrier);
	}
	return NULL;
}

