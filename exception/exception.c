#include "exception.h"
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>


jmp_buf *bufers;
size_t bufer_count = 0;

exception_type last_exception;


void initialize_exception() {
	bufers = (jmp_buf*) malloc(0);
	last_exception.code = 0;
	last_exception.msg = (char*) malloc(0);
}

jmp_buf *exception_newbuf() {
	bufer_count++;
	bufers = (jmp_buf*) realloc((void*) bufers, sizeof(jmp_buf) * bufer_count);
	return &bufers[bufer_count-1];
}

void exception_endbuf() {
	bufer_count--;
	bufers = (jmp_buf*) realloc((void*) bufers, sizeof(jmp_buf) * bufer_count);
}

void throw(const char *msg, int code) {
	last_exception.code = code;
	if (!bufer_count) {
		fprintf(stderr, "Uncaught exception of code %d and message: %s\n", code, msg);
		exception_end();
		raise(SIGSEGV);
	}
	free((void*) last_exception.msg);
	last_exception.msg = (char*) malloc( sizeof(char)*(strlen(msg)+1) );
	strcpy(last_exception.msg, msg);
	longjmp(bufers[bufer_count-1], code);
}

const exception_type exception_get_last(){
	return last_exception;
}

void exception_end() {
	bufer_count = 0;
	last_exception.code = 0;
	free((void*) last_exception.msg);
	free((void*) bufers);
}
