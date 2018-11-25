#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include <setjmp.h>


typedef struct trycatch_exception {
	int code;
	char *msg;
} exception_type;

void initialize_exception();
jmp_buf *exception_newbuf();
void exception_endbuf();
void throw(const char *msg, int code);
const exception_type exception_get_last();
void exception_end();


#define try \
	if (!setjmp(*exception_newbuf())) {

#define catch(x) \
		exception_endbuf(); \
	} \
	else { \
		exception_endbuf(); \
		const exception_type x = exception_get_last();

#define end_try_catch \
	}


#endif
