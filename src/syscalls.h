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
#include <unistd.h>

extern uint32_t __heap_start__;
extern uint32_t __heap_end__;

void *_sbrk(int incr);

void __malloc_lock(struct _reent *reent);

void __malloc_unlock(struct _reent *reent);

// Dummys
int _getpid_r(struct _reent *ptr);

int _kill_r(struct _reent *ptr, int pid, int sig);

void _exit(int status);

_ssize_t _write_r(struct _reent *ptr, int fd, const void *buf, size_t cnt);

int _close_r(struct _reent *ptr, int fd);

int _fstat_r(struct _reent *pt, int fd, struct stat *pstat);

int _isatty_r(struct _reent *ptr, int fd);

off_t _lseek_r(struct _reent *ptr, int fd, off_t pos, int whence);

_ssize_t _read_r(struct _reent *ptr, int fd, void *buf, size_t cnt);

#ifdef __cplusplus
}
#endif

#endif /* SYSCALLS_H_ */
