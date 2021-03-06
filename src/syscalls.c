/*
 * syscalls.c
 *
 *  Created on: May 28, 2012
 *      Author: narf
 */
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include "stm32f4xx.h"

/* set by linker -> value is undefined only the address of the variable is useful */
#include "syscalls.h"

void *_sbrk(int incr) {
	static unsigned char *heap = NULL;
	unsigned char *prev_heap;

	if (heap == NULL ) {
		// start address of heap
		heap = (unsigned char *) &__heap_start__;
	}
	prev_heap = heap;

	if ((heap + incr) >= (unsigned char *) &__heap_end__) {
		return 0;
	}
	heap += incr;
	return (void *) prev_heap;
}

int lock = 0;

void __malloc_lock(struct _reent *reent) {
	__disable_irq();
	++lock;
}

void __malloc_unlock(struct _reent *reent) {
	--lock;
	if (lock == 0) {
		__enable_irq();
	}
}

int _getpid_r(struct _reent *ptr) {
	return 0;
}

int _kill_r(struct _reent *ptr, int pid, int sig) {
	return 0;
}

void _exit(int status) {
	while (1)
		;
}

_ssize_t _write_r(struct _reent *ptr, int fd, const void *buf, size_t cnt) {
	return 0;
}

int _close_r(struct _reent *ptr, int fd) {
	return 0;
}

int _fstat_r(struct _reent *pt, int fd, struct stat *pstat) {
	return 0;
}

int _isatty_r(struct _reent *ptr, int fd) {
	return 0;
}

off_t _lseek_r(struct _reent *ptr, int fd, off_t pos, int whence) {
	return 0;
}

_ssize_t _read_r(struct _reent *ptr, int fd, void *buf, size_t cnt){
	return 0;
}
