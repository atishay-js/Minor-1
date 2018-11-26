#include "exception.h"
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>


jmp_buf *bufers;                                               //array is declared of type jmp_buf
size_t bufer_count = 0;                                        //variable count is initialized of type size_t 

exception_type last_exception;                                 //exception_type is a typeof datatype which contain a integer code and a char msg, last_exception is its variable 


void initialize_exception() {
	bufers = (jmp_buf*) malloc(0);                         //bufer=NULL,it helps to free memory
	last_exception.code = 0;                              
	last_exception.msg = (char*) malloc(0);
}

jmp_buf *exception_newbuf() {
	bufer_count++;
	bufers = (jmp_buf*) realloc((void*) bufers, sizeof(jmp_buf) * bufer_count);              //resize the memory block of bufer
	return &bufers[bufer_count-1];                           //return bufer array
}

void exception_endbuf() {
	bufer_count--;
	bufers = (jmp_buf*) realloc((void*) bufers, sizeof(jmp_buf) * bufer_count);
}

void throw(const char *msg, int code) {
	last_exception.code = code;
	if (!bufer_count) {
		fprintf(stderr, "Uncaught exception of code %d and message: %s\n", code, msg);       //printing exception message using stderr
		exception_end();
		raise(SIGSEGV);                                 //it is raising a signal
	}
	free((void*) last_exception.msg);                      //freeing the message memory
	last_exception.msg = (char*) malloc( sizeof(char)*(strlen(msg)+1) );        //allocating the memory to msg
	strcpy(last_exception.msg, msg);                       
	longjmp(bufers[bufer_count-1], code);                   //calling longjmp 
}

const exception_type exception_get_last(){
	return last_exception;
}

void exception_end() {
	bufer_count = 0;
	last_exception.code = 0;
	free((void*) last_exception.msg);                      //freeing memory of msg
	free((void*) bufers);                                  //freeing memory of array bufers
}
