//File edited by soys - Shame of you sniper - 27.March.2021
/**
 * @file Core17.c
 * @generated by CPrinter
 * @date Sun Mar 14 10:12:14 CET 2021
 *
 * Code generated for processing element Core17 (ID=17).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
#include "ntm.h"
#include <emmintrin.h>
#include <smmintrin.h>
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const Stabilization_0_ComputeBlock__16;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_16 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__150;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_16 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__48;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_48 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__83;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_16 size:= 1024*char defined in Core0
extern coord *const blocksCoord_16__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_16 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_16_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_16__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_16 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_16_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_16_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_16_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_16_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_16__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_16_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_16 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__216;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_16 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__182;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_48 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__115;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_48 size:= 1024*char defined in Core0
extern coord *const blocksCoord_48__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_48 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_48_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_48__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_48 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_48_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_48_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_48_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_48_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_48__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_48_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_48 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__248;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_48 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0

// Core Global Definitions

void *computationThread_Core17(void *arg){
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
		while(lock(17));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		receiveStart(); // Core1 > Core17: Stabilization_0_ComputeBlock__16
		// SyncComGroup = 0
		receiveEnd(1, 17); // Core1 > Core17: Stabilization_0_ComputeBlock__16
		receiveStart(); // Core0 > Core17: Stabilization_0_ComputeBlock__150
		// SyncComGroup = 0
		receiveEnd(0, 17); // Core0 > Core17: Stabilization_0_ComputeBlock__150
		receiveStart(); // Core1 > Core17: Stabilization_0_ComputeBlock__48
		// SyncComGroup = 0
		receiveEnd(1, 17); // Core1 > Core17: Stabilization_0_ComputeBlock__48
		receiveStart(); // Core1 > Core17: Stabilization_0_ComputeBlock__83
		// SyncComGroup = 0
		receiveEnd(1, 17); // Core1 > Core17: Stabilization_0_ComputeBlock__83
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_16__blockCoord__0,blocksData_16__blockData__0,out_16_65__previousFrame__0,vector__vectors_16__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_16
		// SyncComGroup = 1
		sendStart(17, 0); // Core17 > Core0: Stabilization_0_ComputeBlock__216
		sendEnd(); // Core17 > Core0: Stabilization_0_ComputeBlock__216
		receiveStart(); // Core0 > Core17: Stabilization_0_ComputeBlock__182
		// SyncComGroup = 2
		receiveEnd(0, 17); // Core0 > Core17: Stabilization_0_ComputeBlock__182
		receiveStart(); // Core1 > Core17: Stabilization_0_ComputeBlock__115
		// SyncComGroup = 2
		receiveEnd(1, 17); // Core1 > Core17: Stabilization_0_ComputeBlock__115
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_48__blockCoord__0,blocksData_48__blockData__0,out_48_65__previousFrame__0,vector__vectors_48__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_48
		// SyncComGroup = 3
		sendStart(17, 0); // Core17 > Core0: Stabilization_0_ComputeBlock__248
		sendEnd(); // Core17 > Core0: Stabilization_0_ComputeBlock__248
	}
	return NULL;
}

