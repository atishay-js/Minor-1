#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include <setjmp.h>


typedef struct trycatch_exception {                             	//declaring a new type named exception_type
	int code;
	char *msg;
} exception_type;

void initialize_exception();
jmp_buf *exception_newbuf();        					//function for interior calling of setjump()
void exception_endbuf();
void throw(const char *msg, int code);
const exception_type exception_get_last();      			//returning variable of exception_type
void exception_end();							/*initializing count and code to 0 and freeing the memory of 
									  msg and bufer array*/

#define try \
	if (!setjmp(*exception_newbuf())) {				//calling setjmp and passing function to it

#define catch(x) \
		exception_endbuf(); \
	} \
	else { \
		exception_endbuf(); \
		const exception_type x = exception_get_last();

#define end_try_catch \
	}


#endif
