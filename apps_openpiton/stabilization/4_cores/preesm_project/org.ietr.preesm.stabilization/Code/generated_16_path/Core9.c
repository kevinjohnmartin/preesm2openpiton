//File edited by soys - Shame of you sniper - 19.March.2021
/**
 * @file Core9.c
 * @generated by CPrinter
 * @date Sun Mar 14 10:06:25 CET 2021
 *
 * Code generated for processing element Core9 (ID=9).
 */

#include "preesm_gen.h"
#include "path_sniper.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const Stabilization_0_ComputeBlock__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_9 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__25;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_25 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__143;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_9 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__159;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_25 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__41;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_41 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__57;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_57 size:= 72720*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__76;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_9 size:= 1024*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__92;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_25 size:= 1024*char defined in Core0
extern coord *const blocksCoord_25__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_25 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_25_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_25__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_25 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_25_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_25_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_25_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_25_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_25__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_25_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_25 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__225;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_25 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__175;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_41 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__108;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_41 size:= 1024*char defined in Core0
extern coord *const blocksCoord_41__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_41 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_41_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_41__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_41 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_41_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_41_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_41_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_41_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_41__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_41_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_41 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__241;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_41 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__191;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_57 size:= 8*char defined in Core0
extern char *const Stabilization_0_ComputeBlock__124;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_57 size:= 1024*char defined in Core0
extern coord *const blocksCoord_57__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_57 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_57_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_57__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_57 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_57_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_57_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_57_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_57_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_57__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_57_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_57 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__257;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_57 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0
extern coord *const blocksCoord_9__blockCoord__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksCoord_blocksCoord_9 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_9_blockCoord size:= 1*coord defined in Core0
extern uchar *const blocksData_9__blockData__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_explode_Stabilization_0_ComputeBlockMotionVectorss_0_DivideBlocks_0_blocksData_blocksData_9 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_9_blockData size:= 1024*uchar defined in Core0
extern uchar *const out_9_65__previousFrame__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_DuplicatePreviousFrame_0_out_9_65 > Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_9_previousFrame size:= 72720*uchar defined in Core0
extern coord *const vector__vectors_9__0;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_9_vector > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors_vectors_9 size:= 1*coord defined in Core0
extern char *const Stabilization_0_ComputeBlock__209;  // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_9 > Stabilization_0_implode_Stabilization_0_FindDominatingMotion_0_vectors size:= 8*char defined in Core0

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
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__0
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__0
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__25
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__25
		receiveStart(); // Core0 > Core9: Stabilization_0_ComputeBlock__143
		// SyncComGroup = 0
		receiveEnd(0, 9); // Core0 > Core9: Stabilization_0_ComputeBlock__143
		receiveStart(); // Core0 > Core9: Stabilization_0_ComputeBlock__159
		// SyncComGroup = 0
		receiveEnd(0, 9); // Core0 > Core9: Stabilization_0_ComputeBlock__159
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__41
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__41
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__57
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__57
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__76
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__76
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__92
		// SyncComGroup = 0
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__92
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_25__blockCoord__0,blocksData_25__blockData__0,out_25_65__previousFrame__0,vector__vectors_25__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_25
		// SyncComGroup = 1
		sendStart(9, 0); // Core9 > Core0: Stabilization_0_ComputeBlock__225
		sendEnd(); // Core9 > Core0: Stabilization_0_ComputeBlock__225
		receiveStart(); // Core0 > Core9: Stabilization_0_ComputeBlock__175
		// SyncComGroup = 2
		receiveEnd(0, 9); // Core0 > Core9: Stabilization_0_ComputeBlock__175
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__108
		// SyncComGroup = 2
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__108
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_41__blockCoord__0,blocksData_41__blockData__0,out_41_65__previousFrame__0,vector__vectors_41__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_41
		// SyncComGroup = 3
		sendStart(9, 0); // Core9 > Core0: Stabilization_0_ComputeBlock__241
		sendEnd(); // Core9 > Core0: Stabilization_0_ComputeBlock__241
		receiveStart(); // Core0 > Core9: Stabilization_0_ComputeBlock__191
		// SyncComGroup = 4
		receiveEnd(0, 9); // Core0 > Core9: Stabilization_0_ComputeBlock__191
		receiveStart(); // Core1 > Core9: Stabilization_0_ComputeBlock__124
		// SyncComGroup = 4
		receiveEnd(1, 9); // Core1 > Core9: Stabilization_0_ComputeBlock__124
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_57__blockCoord__0,blocksData_57__blockData__0,out_57_65__previousFrame__0,vector__vectors_57__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_57
		// SyncComGroup = 5
		sendStart(9, 0); // Core9 > Core0: Stabilization_0_ComputeBlock__257
		sendEnd(); // Core9 > Core0: Stabilization_0_ComputeBlock__257
		computeBlockMotionVector(360/*width*/,202/*height*/,32/*blockWidth*/,32/*blockHeight*/,38/*maxDeltaX*/,21/*maxDeltaY*/,blocksCoord_9__blockCoord__0,blocksData_9__blockData__0,out_9_65__previousFrame__0,vector__vectors_9__0); // Stabilization_0_ComputeBlockMotionVectorss_0_ComputeBlockMotionVector_9
		// SyncComGroup = 6
		sendStart(9, 0); // Core9 > Core0: Stabilization_0_ComputeBlock__209
		sendEnd(); // Core9 > Core0: Stabilization_0_ComputeBlock__209
	}
	return NULL;
}

