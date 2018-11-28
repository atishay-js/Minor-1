#include "exceptionblast.h"
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>


jmp_buf *buffer;
size_t buffer_count = 0;

exception_type last_exception;


void initialize_exception() {
	buffer = (jmp_buf*) malloc(0);
	last_exception.code = 0;
	last_exception.msg = (char*) malloc(0);
}

jmp_buf *new_buffer() {
	buffer_count++;
	buffer = (jmp_buf*) realloc((void*) buffer, sizeof(jmp_buf) * buffer_count);
	return &buffer[buffer_count-1];
}

void end_buffer() {
	buffer_count--;
	buffer = (jmp_buf*) realloc((void*) buffer, sizeof(jmp_buf) * buffer_count);
}

void throw(const char *msg, int code) {
	last_exception.code = code;
	if (!buffer_count) {
		fprintf(stderr, "Uncaught exception of code %d and message: %s\n", code, msg);
		finalize_exception();
		raise(SIGSEGV);
	}
	free((void*) last_exception.msg);
	last_exception.msg = (char*) malloc( sizeof(char)*(strlen(msg)+1) );
	strcpy(last_exception.msg, msg);
	longjmp(buffer[buffer_count-1], code);
}

const exception_type get_last_exception(){
	return last_exception;
}

void finalize_exception() {
	buffer_count = 0;
	last_exception.code = 0;
	free((void*) last_exception.msg);
	free((void*) buffer);
}
