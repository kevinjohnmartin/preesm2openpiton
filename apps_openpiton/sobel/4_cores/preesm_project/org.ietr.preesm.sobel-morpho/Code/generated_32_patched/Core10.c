//File edited by soys - Shame of you sniper - 18.March.2021
/**
 * @file Core10.c
 * @generated by InstrumentedCPrinter
 * @date Thu Mar 18 19:09:15 CET 2021
 *
 * Code generated for processing element Core10 (ID=10).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Split_0_output__Sobe__2;  // explode_Split_0_output > Sobel_2 size:= 6688*char defined in Core0
extern uchar *const output_2__input__0;  // explode_Split_0_output_output_2 > Sobel_2_input size:= 6688*uchar defined in Core0
extern uchar *const output__y_2__0;  // Erosion_2_output > implode_display_0_y_y_2 size:= 3168*uchar defined in Core0
extern char *const Erosion_2__implode_display_0__0;  // Erosion_2 > implode_display_0_y size:= 3168*char defined in Core0
extern uint64_t dumpedTimes[381]; //  size:= 381*uint64_t
extern int nbExec[381]; //  size:= 381*int

// Core Global Definitions
char Core10[10560]; //  size:= 10560*char
char *const Sobel_2__Dilation_2__0 = (char*) (Core10+0);  // Sobel_2 > Dilation_2 size:= 5984*char
char *const Dilation_2__Erosion_2__0 = (char*) (Core10+5984);  // Dilation_2 > Erosion_2 size:= 4576*char
uchar *const output__input__4 = (uchar*) (Core10+0);  // Sobel_2_output > Dilation_2_input size:= 5984*uchar
uchar *const output__input__5 = (uchar*) (Core10+5984);  // Dilation_2_output > Erosion_2_input size:= 4576*uchar
int idx;

void *computationThread_Core10(void *arg){
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
		while(lock(10));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		dumpTime(205/*globalID*/,dumpedTimes); // 
		*(nbExec+206) = 0;
		receiveStart(); // Core0 > Core10: explode_Split_0_output__Sobe__2
		dumpTime(206/*globalID*/,dumpedTimes); // 
		*(nbExec+207) = 0;
		receiveEnd(0, 10); // Core0 > Core10: explode_Split_0_output__Sobe__2
		dumpTime(207/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+208); idx++){
			sobel(352/*width*/,19/*height*/,output_2__input__0,output__input__4); // Sobel_2
		}
		dumpTime(208/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+209); idx++){
			dilation(17/*height*/,352/*width*/,2/*window*/,output__input__4,output__input__5); // Dilation_2
		}
		dumpTime(209/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+210); idx++){
			erosion(13/*height*/,352/*width*/,2/*window*/,output__input__5,output__y_2__0); // Erosion_2
		}
		dumpTime(210/*globalID*/,dumpedTimes); // 
		*(nbExec+211) = 0;
		sendStart(10, 0); // Core10 > Core0: Erosion_2__implode_display_0__0
		dumpTime(211/*globalID*/,dumpedTimes); // 
		*(nbExec+212) = 0;
		sendEnd(); // Core10 > Core0: Erosion_2__implode_display_0__0
		dumpTime(212/*globalID*/,dumpedTimes); // 
		while(lock(10));
//		pthread_barrier_wait(&iter_barrier);
	}
	return NULL;
}
