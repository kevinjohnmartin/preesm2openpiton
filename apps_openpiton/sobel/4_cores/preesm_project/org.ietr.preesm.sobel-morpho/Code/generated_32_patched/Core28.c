//File edited by soys - Shame of you sniper - 18.March.2021
/**
 * @file Core28.c
 * @generated by InstrumentedCPrinter
 * @date Thu Mar 18 19:09:15 CET 2021
 *
 * Code generated for processing element Core28 (ID=28).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Split_0_output__Sobe__20;  // explode_Split_0_output > Sobel_20 size:= 6688*char defined in Core0
extern uchar *const output_20__input__0;  // explode_Split_0_output_output_20 > Sobel_20_input size:= 6688*uchar defined in Core0
extern uchar *const output__y_20__0;  // Erosion_20_output > implode_display_0_y_y_20 size:= 3168*uchar defined in Core0
extern char *const Erosion_20__implode_display___0;  // Erosion_20 > implode_display_0_y size:= 3168*char defined in Core0
extern uint64_t dumpedTimes[381]; //  size:= 381*uint64_t
extern int nbExec[381]; //  size:= 381*int

// Core Global Definitions
char Core28[10560]; //  size:= 10560*char
char *const Sobel_20__Dilation_20__0 = (char*) (Core28+0);  // Sobel_20 > Dilation_20 size:= 5984*char
char *const Dilation_20__Erosion_20__0 = (char*) (Core28+5984);  // Dilation_20 > Erosion_20 size:= 4576*char
uchar *const output__input__40 = (uchar*) (Core28+0);  // Sobel_20_output > Dilation_20_input size:= 5984*uchar
uchar *const output__input__41 = (uchar*) (Core28+5984);  // Dilation_20_output > Erosion_20_input size:= 4576*uchar
int idx;

void *computationThread_Core28(void *arg){
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
		while(lock(28));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		dumpTime(349/*globalID*/,dumpedTimes); // 
		*(nbExec+350) = 0;
		receiveStart(); // Core0 > Core28: explode_Split_0_output__Sobe__20
		dumpTime(350/*globalID*/,dumpedTimes); // 
		*(nbExec+351) = 0;
		receiveEnd(0, 28); // Core0 > Core28: explode_Split_0_output__Sobe__20
		dumpTime(351/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+352); idx++){
			sobel(352/*width*/,19/*height*/,output_20__input__0,output__input__40); // Sobel_20
		}
		dumpTime(352/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+353); idx++){
			dilation(17/*height*/,352/*width*/,2/*window*/,output__input__40,output__input__41); // Dilation_20
		}
		dumpTime(353/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+354); idx++){
			erosion(13/*height*/,352/*width*/,2/*window*/,output__input__41,output__y_20__0); // Erosion_20
		}
		dumpTime(354/*globalID*/,dumpedTimes); // 
		*(nbExec+355) = 0;
		sendStart(28, 0); // Core28 > Core0: Erosion_20__implode_display___0
		dumpTime(355/*globalID*/,dumpedTimes); // 
		*(nbExec+356) = 0;
		sendEnd(); // Core28 > Core0: Erosion_20__implode_display___0
		dumpTime(356/*globalID*/,dumpedTimes); // 
		while(lock(28));
//		pthread_barrier_wait(&iter_barrier);
	}
	return NULL;
}
