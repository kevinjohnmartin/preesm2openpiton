/**
 * @file Core18.c
 * @generated by InstrumentedCPrinter
 * @date Thu Mar 18 19:09:15 CET 2021
 *
 * Code generated for processing element Core18 (ID=18).
 */

#include "preesm_gen.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Split_0_output__Sobe__10;  // explode_Split_0_output > Sobel_10 size:= 6688*char defined in Core0
extern uchar *const output_10__input__0;  // explode_Split_0_output_output_10 > Sobel_10_input size:= 6688*uchar defined in Core0
extern uchar *const output__y_10__0;  // Erosion_10_output > implode_display_0_y_y_10 size:= 3168*uchar defined in Core0
extern char *const Erosion_10__implode_display___0;  // Erosion_10 > implode_display_0_y size:= 3168*char defined in Core0
extern uint64_t dumpedTimes[381]; //  size:= 381*uint64_t
extern int nbExec[381]; //  size:= 381*int

// Core Global Definitions
char Core18[10560]; //  size:= 10560*char
char *const Sobel_10__Dilation_10__0 = (char*) (Core18+0);  // Sobel_10 > Dilation_10 size:= 5984*char
char *const Dilation_10__Erosion_10__0 = (char*) (Core18+5984);  // Dilation_10 > Erosion_10 size:= 4576*char
uchar *const output__input__20 = (uchar*) (Core18+0);  // Sobel_10_output > Dilation_10_input size:= 5984*uchar
uchar *const output__input__21 = (uchar*) (Core18+5984);  // Dilation_10_output > Erosion_10_input size:= 4576*uchar
int idx;

void *computationThread_Core18(void *arg){
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
		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		dumpTime(269/*globalID*/,dumpedTimes); // 
		*(nbExec+270) = 0;
		receiveStart(); // Core0 > Core18: explode_Split_0_output__Sobe__10
		dumpTime(270/*globalID*/,dumpedTimes); // 
		*(nbExec+271) = 0;
		receiveEnd(0, 18); // Core0 > Core18: explode_Split_0_output__Sobe__10
		dumpTime(271/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+272); idx++){
			sobel(352/*width*/,19/*height*/,output_10__input__0,output__input__20); // Sobel_10
		}
		dumpTime(272/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+273); idx++){
			dilation(17/*height*/,352/*width*/,2/*window*/,output__input__20,output__input__21); // Dilation_10
		}
		dumpTime(273/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+274); idx++){
			erosion(13/*height*/,352/*width*/,2/*window*/,output__input__21,output__y_10__0); // Erosion_10
		}
		dumpTime(274/*globalID*/,dumpedTimes); // 
		*(nbExec+275) = 0;
		sendStart(18, 0); // Core18 > Core0: Erosion_10__implode_display___0
		dumpTime(275/*globalID*/,dumpedTimes); // 
		*(nbExec+276) = 0;
		sendEnd(); // Core18 > Core0: Erosion_10__implode_display___0
		dumpTime(276/*globalID*/,dumpedTimes); // 
		pthread_barrier_wait(&iter_barrier);
	}
	return NULL;
}
