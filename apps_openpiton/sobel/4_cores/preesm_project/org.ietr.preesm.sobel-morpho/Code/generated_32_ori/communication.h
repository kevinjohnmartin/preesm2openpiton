/**
 * Copyright or © or Copr. IETR/INSA - Rennes (2017 - 2019) :
 *
 * Antoine Morvan <antoine.morvan@insa-rennes.fr> (2017 - 2019)
 * Florian Arrestier <florian.arrestier@insa-rennes.fr> (2018)
 * Julien Hascoet <jhascoet@kalray.eu> (2017)
 *
 * This software is a computer program whose purpose is to help prototyping
 * parallel applications using dataflow formalism.
 *
 * This software is governed by the CeCILL  license under French law and
 * abiding by the rules of distribution of free software.  You can  use,
 * modify and/ or redistribute the software under the terms of the CeCILL
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info".
 *
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability.
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or
 * data to be ensured and,  more generally, to use and operate it in the
 * same conditions as regards security.
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license and that you accept its terms.
 */
/*
============================================================================
Name        : communication.h
Author      : kdesnos
Version     : 2.0
Copyright   : CECILL-C
Description : Communication primitive for Preesm Codegen.
Currently, primitives were tested only for x86, shared_mem
communications.
============================================================================
*/

#ifndef _PREESM_COMMUNICATION_H
#define _PREESM_COMMUNICATION_H

#ifdef __APPLE__
#include <dispatch/dispatch.h>
#else
#include <semaphore.h>
#endif

// note: rk_ struct and functions comes from
// https://stackoverflow.com/questions/27736618/why-are-sem-init-sem-getvalue-sem-destroy-deprecated-on-mac-os-x-and-w

struct rk_sema {
#ifdef __APPLE__
    dispatch_semaphore_t    sem;
#else
    sem_t                   sem;
#endif
};


static void rk_sema_init(struct rk_sema *s, int value) {
#ifdef __APPLE__
    dispatch_semaphore_t *sem = &s->sem;
    *sem = dispatch_semaphore_create(value);
#else
    sem_init(&s->sem, 0, value);
#endif
}

static void rk_sema_wait(struct rk_sema *s) {
#ifdef __APPLE__
    dispatch_semaphore_wait(s->sem, DISPATCH_TIME_FOREVER);
#else
    int r;
    do {
            r = sem_wait(&s->sem);
    } while (r == -1);
#endif
}

static void rk_sema_post(struct rk_sema *s) {
#ifdef __APPLE__
    dispatch_semaphore_signal(s->sem);
#else
    sem_post(&s->sem);
#endif
}

/**
* Maximum number of core supported by the communication library.
* This number is used to allocate the table of semaphores used for intercore
* synchronization.
*/
#define MAX_NB_CORES 32

/**
* Initialize the semaphores used for inter-core synchronization.
*/
void communicationInit();

/**
* Non-blocking function called by the sender to signal that a buffer is ready
* to be sent.
*
* @param[in] senderID
*        the ID of the sender core
* @param[in] coreID
*        the ID of the receiver core
*/
void sendStart(int senderID, int receveirID);

/**
* Blocking function (not for shared_mem communication) called by the sender to
* signal that communication is completed.
*/
void sendEnd();

/**
* Non-blocking function called by the receiver begin receiving the
* data. (not implemented with shared memory communications).
*/
void receiveStart();

/**
* Blocking function called by the sender to wait for the received data
* availability.
*
* @param[in] senderID
*        the ID of the sender core
* @param[in] coreID
*        the ID of the receiver core
*/
void receiveEnd(int senderID, int receveirID);

#endif
