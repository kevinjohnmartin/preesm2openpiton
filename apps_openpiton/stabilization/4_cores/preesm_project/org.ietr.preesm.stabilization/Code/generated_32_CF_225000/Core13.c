//File edited by soys - Shame of you sniper - 27.March.2021
//File edited by Cowa - CoW automatic script - 27.March.2021
/**
 * @file Core13.c
 * @generated by CPrinter
 * @date Sun Mar 14 10:12:14 CET 2021
 *
 * Code generated for processing element Core13 (ID=13).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
#include "cow_master.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const Stabilization_0_ComputeBlock__12;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_12 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__146;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_12 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__44;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_44 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__79;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_12 size:= 1024*char defined in Core0
extern coord *const blocksCoord_12__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_12 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_12_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_12__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_12 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_12_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_12_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_12_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_12_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_12__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_12_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_12 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__212;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_12 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__178;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_44 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__111;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_44 size:= 1024*char defined in Core0
extern coord *const blocksCoord_44__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_44 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_44_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_44__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_44 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_44_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_44_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_44_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_44_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_44__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_44_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_44 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__244;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_44 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0

// Core Global Definitions

void *computationThread_Core13(void *arg){
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
		while(lock(13));
//		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		receiveStart(); // Core1 > Core13: Stabilization_0_ComputeBlock__12
		// SyncComGroup = 0
		receiveEnd(1, 13); // Core1 > Core13: Stabilization_0_ComputeBlock__12
		receiveStart(); // Core0 > Core13: Stabilization_0_ComputeBlock__146
		// SyncComGroup = 0
		receiveEnd(0, 13); // Core0 > Core13: Stabilization_0_ComputeBlock__146
		receiveStart(); // Core1 > Core13: Stabilization_0_ComputeBlock__44
		// SyncComGroup = 0
		receiveEnd(1, 13); // Core1 > Core13: Stabilization_0_ComputeBlock__44
		receiveStart(); // Core1 > Core13: Stabilization_0_ComputeBlock__79
		// SyncComGroup = 0
		receiveEnd(1, 13); // Core1 > Core13: Stabilization_0_ComputeBlock__79
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_12__blockCoord__0,blocksData_12__blockData__0,out_12_65__previousFrame__0,vector__vectors_12__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_12
		// SyncComGroup = 1
		sendStart(13, 0); // Core13 > Core0: Stabilization_0_ComputeBlock__212
		sendEnd(); // Core13 > Core0: Stabilization_0_ComputeBlock__212
		receiveStart(); // Core0 > Core13: Stabilization_0_ComputeBlock__178
		// SyncComGroup = 2
		receiveEnd(0, 13); // Core0 > Core13: Stabilization_0_ComputeBlock__178
		receiveStart(); // Core1 > Core13: Stabilization_0_ComputeBlock__111
		// SyncComGroup = 2
		receiveEnd(1, 13); // Core1 > Core13: Stabilization_0_ComputeBlock__111
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_44__blockCoord__0,blocksData_44__blockData__0,out_44_65__previousFrame__0,vector__vectors_44__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_44
		// SyncComGroup = 3
		sendStart(13, 0); // Core13 > Core0: Stabilization_0_ComputeBlock__244
		sendEnd(); // Core13 > Core0: Stabilization_0_ComputeBlock__244
	}
	return NULL;
}
