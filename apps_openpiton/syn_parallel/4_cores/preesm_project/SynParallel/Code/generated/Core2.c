/**
 * @file Core2.c
 * @generated by CPrinter
 * @date Mon Jan 17 16:55:09 CET 2022
 *
 * Code generated for processing element Core2 (ID=2).
 */

#include "preesm_gen.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const explode_Prod_0_prod_output____1;  // explode_Prod_0_prod_output > Processing_1 size:= 120*char defined in Core0
extern unsigned char *const prod_output_1__input__0;  // explode_Prod_0_prod_output_prod_output_1 > Processing_1_input size:= 120*unsigned char defined in Core0
extern unsigned char *const output__cons_input_1__0;  // Processing_1_output > implode_Cons_0_cons_input_cons_input_1 size:= 120*unsigned char defined in Core0
extern char *const Processing_1__implode_Cons_0__0;  // Processing_1 > implode_Cons_0_cons_input size:= 120*char defined in Core0
extern char *const explode_Prod_0_prod_output____3;  // explode_Prod_0_prod_output > Processing_3 size:= 120*char defined in Core0
extern unsigned char *const prod_output_3__input__0;  // explode_Prod_0_prod_output_prod_output_3 > Processing_3_input size:= 120*unsigned char defined in Core0
extern unsigned char *const output__cons_input_3__0;  // Processing_3_output > implode_Cons_0_cons_input_cons_input_3 size:= 120*unsigned char defined in Core0
extern char *const Processing_3__implode_Cons_0__0;  // Processing_3 > implode_Cons_0_cons_input size:= 120*char defined in Core0
extern char *const explode_Prod_0_prod_output____5;  // explode_Prod_0_prod_output > Processing_5 size:= 120*char defined in Core0
extern unsigned char *const prod_output_5__input__0;  // explode_Prod_0_prod_output_prod_output_5 > Processing_5_input size:= 120*unsigned char defined in Core0
extern unsigned char *const output__cons_input_5__0;  // Processing_5_output > implode_Cons_0_cons_input_cons_input_5 size:= 120*unsigned char defined in Core0
extern char *const Processing_5__implode_Cons_0__0;  // Processing_5 > implode_Cons_0_cons_input size:= 120*char defined in Core0

// Core Global Definitions

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
		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		receiveStart(); // Core0 > Core2: explode_Prod_0_prod_output____1
		// SyncComGroup = 0
		receiveEnd(0, 2); // Core0 > Core2: explode_Prod_0_prod_output____1
		processing(120/*slice_size*/,prod_output_1__input__0,output__cons_input_1__0); // Processing_1
		// SyncComGroup = 1
		sendStart(2, 0); // Core2 > Core0: Processing_1__implode_Cons_0__0
		sendEnd(); // Core2 > Core0: Processing_1__implode_Cons_0__0
		receiveStart(); // Core0 > Core2: explode_Prod_0_prod_output____3
		// SyncComGroup = 2
		receiveEnd(0, 2); // Core0 > Core2: explode_Prod_0_prod_output____3
		processing(120/*slice_size*/,prod_output_3__input__0,output__cons_input_3__0); // Processing_3
		// SyncComGroup = 3
		sendStart(2, 0); // Core2 > Core0: Processing_3__implode_Cons_0__0
		sendEnd(); // Core2 > Core0: Processing_3__implode_Cons_0__0
		receiveStart(); // Core0 > Core2: explode_Prod_0_prod_output____5
		// SyncComGroup = 4
		receiveEnd(0, 2); // Core0 > Core2: explode_Prod_0_prod_output____5
		processing(120/*slice_size*/,prod_output_5__input__0,output__cons_input_5__0); // Processing_5
		// SyncComGroup = 5
		sendStart(2, 0); // Core2 > Core0: Processing_5__implode_Cons_0__0
		sendEnd(); // Core2 > Core0: Processing_5__implode_Cons_0__0
	}
	return NULL;
}

