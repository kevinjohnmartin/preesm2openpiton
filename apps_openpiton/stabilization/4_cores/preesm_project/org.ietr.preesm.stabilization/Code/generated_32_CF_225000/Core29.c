//File edited by soys - Shame of you sniper - 27.March.2021
//File edited by Cowa - CoW automatic script - 27.March.2021
/**
 * @file Core29.c
 * @generated by CPrinter
 * @date Sun Mar 14 10:12:14 CET 2021
 *
 * Code generated for processing element Core29 (ID=29).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
#include "cow_master.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const Stabilization_0_ComputeBlock__27;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_27 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__161;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_27 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__59;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_59 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__94;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_27 size:= 1024*char defined in Core0
extern coord *const blocksCoord_27__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_27 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_27_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_27__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_27 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_27_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_27_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_27_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_27_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_27__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_27_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_27 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__227;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_27 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__193;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_59 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__126;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_59 size:= 1024*char defined in Core0
extern coord *const blocksCoord_59__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_59 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_59_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_59__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_59 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_59_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_59_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_59_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_59_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_59__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_59_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_59 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__259;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_59 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0

// Core Global Definitions

void *computationThread_Core29(void *arg){
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
		reconfigure_CoW(index);
		while(lock(29));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		receiveStart(); // Core1 > Core29: Stabilization_0_ComputeBlock__27
		// SyncComGroup = 0
		receiveEnd(1, 29); // Core1 > Core29: Stabilization_0_ComputeBlock__27
		receiveStart(); // Core0 > Core29: Stabilization_0_ComputeBlock__161
		// SyncComGroup = 0
		receiveEnd(0, 29); // Core0 > Core29: Stabilization_0_ComputeBlock__161
		receiveStart(); // Core1 > Core29: Stabilization_0_ComputeBlock__59
		// SyncComGroup = 0
		receiveEnd(1, 29); // Core1 > Core29: Stabilization_0_ComputeBlock__59
		receiveStart(); // Core1 > Core29: Stabilization_0_ComputeBlock__94
		// SyncComGroup = 0
		receiveEnd(1, 29); // Core1 > Core29: Stabilization_0_ComputeBlock__94
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_27__blockCoord__0,blocksData_27__blockData__0,out_27_65__previousFrame__0,vector__vectors_27__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_27
		// SyncComGroup = 1
		sendStart(29, 0); // Core29 > Core0: Stabilization_0_ComputeBlock__227
		sendEnd(); // Core29 > Core0: Stabilization_0_ComputeBlock__227
		receiveStart(); // Core0 > Core29: Stabilization_0_ComputeBlock__193
		// SyncComGroup = 2
		receiveEnd(0, 29); // Core0 > Core29: Stabilization_0_ComputeBlock__193
		receiveStart(); // Core1 > Core29: Stabilization_0_ComputeBlock__126
		// SyncComGroup = 2
		receiveEnd(1, 29); // Core1 > Core29: Stabilization_0_ComputeBlock__126
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_59__blockCoord__0,blocksData_59__blockData__0,out_59_65__previousFrame__0,vector__vectors_59__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_59
		// SyncComGroup = 3
		sendStart(29, 0); // Core29 > Core0: Stabilization_0_ComputeBlock__259
		sendEnd(); // Core29 > Core0: Stabilization_0_ComputeBlock__259
	}
	return NULL;
}

