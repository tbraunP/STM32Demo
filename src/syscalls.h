/*
 * syscalls.h
 *
 *  Created on: 15.09.2012
 *      Author: pyro
 */

#ifndef SYSCALLS_H_
#define SYSCALLS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <reent.h>

extern uint32_t __heap_start__;
extern uint32_t __heap_end__;

void *_sbrk(int incr);

void __malloc_lock(struct _reent *reent);

void __malloc_unlock(struct _reent *reent);

int _getpid_r(struct _reent *ptr);

int _kill_r(struct _reent *ptr, int pid, int sig);

void _exit(int status);

#ifdef __cplusplus
}
#endif

#endif /* SYSCALLS_H_ */
