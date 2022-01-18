//File edited by soys - Shame of you sniper - 18.March.2021
/**
 * @file Core7.c
 * @generated by InstrumentedCPrinter
 * @date Thu Mar 18 19:09:15 CET 2021
 *
 * Code generated for processing element Core7 (ID=7).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Split_0_output__Sobe__28;  // explode_Split_0_output > Sobel_28 size:= 6688*char defined in Core0
extern uchar *const output_28__input__0;  // explode_Split_0_output_output_28 > Sobel_28_input size:= 6688*uchar defined in Core0
extern uchar *const output__y_28__0;  // Erosion_28_output > implode_display_0_y_y_28 size:= 3168*uchar defined in Core0
extern char *const Erosion_28__implode_display___0;  // Erosion_28 > implode_display_0_y size:= 3168*char defined in Core0
extern uint64_t dumpedTimes[381]; //  size:= 381*uint64_t
extern int nbExec[381]; //  size:= 381*int

// Core Global Definitions
char Core7[10560]; //  size:= 10560*char
char *const Sobel_28__Dilation_28__0 = (char*) (Core7+0);  // Sobel_28 > Dilation_28 size:= 5984*char
char *const Dilation_28__Erosion_28__0 = (char*) (Core7+5984);  // Dilation_28 > Erosion_28 size:= 4576*char
uchar *const output__input__56 = (uchar*) (Core7+0);  // Sobel_28_output > Dilation_28_input size:= 5984*uchar
uchar *const output__input__57 = (uchar*) (Core7+5984);  // Dilation_28_output > Erosion_28_input size:= 4576*uchar
int idx;

void *computationThread_Core7(void *arg){
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
		while(lock(7));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		dumpTime(181/*globalID*/,dumpedTimes); // 
		*(nbExec+182) = 0;
		receiveStart(); // Core0 > Core7: explode_Split_0_output__Sobe__28
		dumpTime(182/*globalID*/,dumpedTimes); // 
		*(nbExec+183) = 0;
		receiveEnd(0, 7); // Core0 > Core7: explode_Split_0_output__Sobe__28
		dumpTime(183/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+184); idx++){
			sobel(352/*width*/,19/*height*/,output_28__input__0,output__input__56); // Sobel_28
		}
		dumpTime(184/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+185); idx++){
			dilation(17/*height*/,352/*width*/,2/*window*/,output__input__56,output__input__57); // Dilation_28
		}
		dumpTime(185/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+186); idx++){
			erosion(13/*height*/,352/*width*/,2/*window*/,output__input__57,output__y_28__0); // Erosion_28
		}
		dumpTime(186/*globalID*/,dumpedTimes); // 
		*(nbExec+187) = 0;
		sendStart(7, 0); // Core7 > Core0: Erosion_28__implode_display___0
		dumpTime(187/*globalID*/,dumpedTimes); // 
		*(nbExec+188) = 0;
		sendEnd(); // Core7 > Core0: Erosion_28__implode_display___0
		dumpTime(188/*globalID*/,dumpedTimes); // 
		while(lock(7));
//		pthread_barrier_wait(&iter_barrier);
	}
	return NULL;
}
