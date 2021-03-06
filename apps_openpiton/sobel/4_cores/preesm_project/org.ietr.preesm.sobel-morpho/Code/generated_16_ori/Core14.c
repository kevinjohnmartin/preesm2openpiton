/**
 * @file Core14.c
 * @generated by InstrumentedCPrinter
 * @date Thu Mar 18 19:00:00 CET 2021
 *
 * Code generated for processing element Core14 (ID=14).
 */

#include "preesm_gen.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Split_0_output__Sobe__6;  // explode_Split_0_output > Sobel_6 size:= 9856*char defined in Core0
extern uchar *const output_6__input__0;  // explode_Split_0_output_output_6 > Sobel_6_input size:= 9856*uchar defined in Core0
extern uchar *const output__y_6__0;  // Erosion_6_output > implode_display_0_y_y_6 size:= 6336*uchar defined in Core0
extern char *const Erosion_6__implode_display_0__0;  // Erosion_6 > implode_display_0_y size:= 6336*char defined in Core0
extern uint64_t dumpedTimes[189]; //  size:= 189*uint64_t
extern int nbExec[189]; //  size:= 189*int

// Core Global Definitions
char Core14[16896]; //  size:= 16896*char
char *const Sobel_6__Dilation_6__0 = (char*) (Core14+0);  // Sobel_6 > Dilation_6 size:= 9152*char
char *const Dilation_6__Erosion_6__0 = (char*) (Core14+9152);  // Dilation_6 > Erosion_6 size:= 7744*char
uchar *const output__input__12 = (uchar*) (Core14+0);  // Sobel_6_output > Dilation_6_input size:= 9152*uchar
uchar *const output__input__13 = (uchar*) (Core14+9152);  // Dilation_6_output > Erosion_6_input size:= 7744*uchar
int idx;

void *computationThread_Core14(void *arg){
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
		dumpTime(173/*globalID*/,dumpedTimes); // 
		*(nbExec+174) = 0;
		receiveStart(); // Core0 > Core14: explode_Split_0_output__Sobe__6
		dumpTime(174/*globalID*/,dumpedTimes); // 
		*(nbExec+175) = 0;
		receiveEnd(0, 14); // Core0 > Core14: explode_Split_0_output__Sobe__6
		dumpTime(175/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+176); idx++){
			sobel(352/*width*/,28/*height*/,output_6__input__0,output__input__12); // Sobel_6
		}
		dumpTime(176/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+177); idx++){
			dilation(26/*height*/,352/*width*/,2/*window*/,output__input__12,output__input__13); // Dilation_6
		}
		dumpTime(177/*globalID*/,dumpedTimes); // 
		for(idx=0; idx<*(nbExec+178); idx++){
			erosion(22/*height*/,352/*width*/,2/*window*/,output__input__13,output__y_6__0); // Erosion_6
		}
		dumpTime(178/*globalID*/,dumpedTimes); // 
		*(nbExec+179) = 0;
		sendStart(14, 0); // Core14 > Core0: Erosion_6__implode_display_0__0
		dumpTime(179/*globalID*/,dumpedTimes); // 
		*(nbExec+180) = 0;
		sendEnd(); // Core14 > Core0: Erosion_6__implode_display_0__0
		dumpTime(180/*globalID*/,dumpedTimes); // 
		pthread_barrier_wait(&iter_barrier);
	}
	return NULL;
}

