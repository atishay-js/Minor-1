#ifndef __EXCEPTIONBLAST_H__
#define __EXCEPTIONBLAST_H__
#include <setjmp.h>



typedef struct trycatch_exception {
	int code;
	char *msg;
} exception_type;

void initialize_exception();
jmp_buf *new_buffer();
void end_buffer();
void throw(const char *msg, int code);
const exception_type get_last_exception();
void finalize_exception();


#define try \
	if (!setjmp(*new_buffer())) {

#define catch(x) \
		end_buffer(); \
	} \
	else { \
		end_buffer(); \
		const exception_type x = get_last_exception();
	    

#define end_try_catch \
}



#endif
