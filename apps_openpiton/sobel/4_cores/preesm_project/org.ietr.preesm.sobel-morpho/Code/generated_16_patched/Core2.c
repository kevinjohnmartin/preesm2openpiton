//File edited by soys - Shame of you sniper - 18.March.2021
/**
 * @file Core2.c
 * @generated by InstrumentedCPrinter
 * @date Thu Mar 18 19:00:00 CET 2021
 *
 * Code generated for processing element Core2 (ID=2).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Split_0_output__Sobe__8;  // explode_Split_0_output > Sobel_8 size:= 9856*char defined in Core0
extern uchar *const output_8__input__0;  // explode_Split_0_output_output_8 > Sobel_8_input size:= 9856*uchar defined in Core0
extern uchar *const output__y_8__0;  // Erosion_8_output > implode_display_0_y_y_8 size:= 6336*uchar defined in Core0
extern char *const Erosion_8__implode_display_0__0;  // Erosion_8 > implode_display_0_y size:= 6336*char defined in Core0
extern uint64_t dumpedTimes[189]; //  size:= 189*uint64_t
extern int nbExec[189]; //  size:= 189*int

// Core Global Definitions
char Core2[16896]; //  size:= 16896*char
char *const Sobel_8__Dilation_8__0 = (char*) (Core2+0);  // Sobel_8 > Dilation_8 size:= 9152*char
char *const Dilation_8__Erosion_8__0 = (char*) (Core2+9152);  // Dilation_8 > Erosion_8 size:= 7744*char
uchar *const output__input__16 = (uchar*) (Core2+0);  // Sobel_8_output > Dilation_8_input size:= 9152*uchar
uchar *const output__input__17 = (uchar*) (Core2+9152);  // Dilation_8_output > Erosion_8_input size:= 7744*uchar
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
		dumpTime(77/*globalID*/,dumpedTimes); // 
		*(nbExec+78) = 0;
		receiveStart(); // Core0 > Core2: explode_Split_0_output__Sobe__8
		dumpTime(78/*globalID*/,dumpedTimes); // 
		*(nbExec+79) = 0;
		receiveEnd(0, 2); // Core0 > Core2: explode_Split_0_output__Sobe__8
		dumpTime(79/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+80); idx++){
			sobel(352/*width*/,28/*height*/,output_8__input__0,output__input__16); // Sobel_8
		}
		dumpTime(80/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+81); idx++){
			dilation(26/*height*/,352/*width*/,2/*window*/,output__input__16,output__input__17); // Dilation_8
		}
		dumpTime(81/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+82); idx++){
			erosion(22/*height*/,352/*width*/,2/*window*/,output__input__17,output__y_8__0); // Erosion_8
		}
		dumpTime(82/*globalID*/,dumpedTimes); // 
		*(nbExec+83) = 0;
		sendStart(2, 0); // Core2 > Core0: Erosion_8__implode_display_0__0
		dumpTime(83/*globalID*/,dumpedTimes); // 
		*(nbExec+84) = 0;
		sendEnd(); // Core2 > Core0: Erosion_8__implode_display_0__0
		dumpTime(84/*globalID*/,dumpedTimes); // 
		while(lock(2));
//		pthread_barrier_wait(&iter_barrier);
	}
	return NULL;
}

