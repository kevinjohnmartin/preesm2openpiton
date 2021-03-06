//File edited by soys - Shame of you sniper - 18.March.2021
/**
 * @file Core2.c
 * @generated by InstrumentedCPrinter
 * @date Thu Mar 18 19:09:15 CET 2021
 *
 * Code generated for processing element Core2 (ID=2).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Split_0_output__Sobe__12;  // explode_Split_0_output > Sobel_12 size:= 6688*char defined in Core0
extern uchar *const output_12__input__0;  // explode_Split_0_output_output_12 > Sobel_12_input size:= 6688*uchar defined in Core0
extern uchar *const output__y_12__0;  // Erosion_12_output > implode_display_0_y_y_12 size:= 3168*uchar defined in Core0
extern char *const Erosion_12__implode_display___0;  // Erosion_12 > implode_display_0_y size:= 3168*char defined in Core0
extern uint64_t dumpedTimes[381]; //  size:= 381*uint64_t
extern int nbExec[381]; //  size:= 381*int

// Core Global Definitions
char Core2[10560]; //  size:= 10560*char
char *const Sobel_12__Dilation_12__0 = (char*) (Core2+0);  // Sobel_12 > Dilation_12 size:= 5984*char
char *const Dilation_12__Erosion_12__0 = (char*) (Core2+5984);  // Dilation_12 > Erosion_12 size:= 4576*char
uchar *const output__input__24 = (uchar*) (Core2+0);  // Sobel_12_output > Dilation_12_input size:= 5984*uchar
uchar *const output__input__25 = (uchar*) (Core2+5984);  // Dilation_12_output > Erosion_12_input size:= 4576*uchar
int idx;

void *computationThread_Core2(void *arg){
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
		while(lock(2));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		dumpTime(141/*globalID*/,dumpedTimes); // 
		*(nbExec+142) = 0;
		receiveStart(); // Core0 > Core2: explode_Split_0_output__Sobe__12
		dumpTime(142/*globalID*/,dumpedTimes); // 
		*(nbExec+143) = 0;
		receiveEnd(0, 2); // Core0 > Core2: explode_Split_0_output__Sobe__12
		dumpTime(143/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+144); idx++){
			sobel(352/*width*/,19/*height*/,output_12__input__0,output__input__24); // Sobel_12
		}
		dumpTime(144/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+145); idx++){
			dilation(17/*height*/,352/*width*/,2/*window*/,output__input__24,output__input__25); // Dilation_12
		}
		dumpTime(145/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+146); idx++){
			erosion(13/*height*/,352/*width*/,2/*window*/,output__input__25,output__y_12__0); // Erosion_12
		}
		dumpTime(146/*globalID*/,dumpedTimes); // 
		*(nbExec+147) = 0;
		sendStart(2, 0); // Core2 > Core0: Erosion_12__implode_display___0
		dumpTime(147/*globalID*/,dumpedTimes); // 
		*(nbExec+148) = 0;
		sendEnd(); // Core2 > Core0: Erosion_12__implode_display___0
		dumpTime(148/*globalID*/,dumpedTimes); // 
		while(lock(2));
//		pthread_barrier_wait(&iter_barrier);
	}
	return NULL;
}

