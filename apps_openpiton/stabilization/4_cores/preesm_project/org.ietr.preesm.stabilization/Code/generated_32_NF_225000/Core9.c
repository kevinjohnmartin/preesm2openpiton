//File edited by soys - Shame of you sniper - 27.March.2021
/**
 * @file Core9.c
 * @generated by CPrinter
 * @date Sun Mar 14 10:12:14 CET 2021
 *
 * Code generated for processing element Core9 (ID=9).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
#include "ntm.h"
#include <emmintrin.h>
#include <smmintrin.h>
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const Stabilization_0_ComputeBlock__9;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_8 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__40;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_40 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__142;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_8 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__174;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_40 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__75;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_8 size:= 1024*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__107;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_40 size:= 1024*char defined in Core0
extern coord *const blocksCoord_40__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_40 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_40_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_40__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_40 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_40_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_40_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_40_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_40_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_40__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_40_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_40 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__240;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_40 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0
extern coord *const blocksCoord_8__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_8 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_8_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_8__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_8 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_8_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_8_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_8_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_8_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_8__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_8_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_8 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__208;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_8 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0

// Core Global Definitions

void *computationThread_Core9(void *arg){
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
		while(lock(9));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__9
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__9
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__40
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__40
		receiveStart(); // Core0 > Core9: Stabilization_0_ComputeBlock__142
		// SyncComGroup = 0
		receiveEnd(0, 9); // Core0 > Core9: Stabilization_0_ComputeBlock__142
		receiveStart(); // Core0 > Core9: Stabilization_0_ComputeBlock__174
		// SyncComGroup = 0
		receiveEnd(0, 9); // Core0 > Core9: Stabilization_0_ComputeBlock__174
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__75
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__75
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__107
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__107
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_40__blockCoord__0,blocksData_40__blockData__0,out_40_65__previousFrame__0,vector__vectors_40__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_40
		// SyncComGroup = 1
		sendStart(9, 0); // Core9 > Core0: Stabilization_0_ComputeBlock__240
		sendEnd(); // Core9 > Core0: Stabilization_0_ComputeBlock__240
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_8__blockCoord__0,blocksData_8__blockData__0,out_8_65__previousFrame__0,vector__vectors_8__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_8
		// SyncComGroup = 2
		sendStart(9, 0); // Core9 > Core0: Stabilization_0_ComputeBlock__208
		sendEnd(); // Core9 > Core0: Stabilization_0_ComputeBlock__208
	}
	return NULL;
}
