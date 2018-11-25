#include <stdio.h>
#include "exception.h"

int main(int argc, char **argv) {
	initialize_exception();                     //calling the initialize exception method
	try
		printf("Ok!\n");
		throw("An error happened", 1);      //throw must contain error message and error, itself
		printf("Super Ok!\n");
	catch(err)
		fprintf(stderr, "Error %d: %s\n", err.code, err.msg);       //note:fprintf is used
	end_try_catch 
	exception_end();                            //calling the end exception method
	return 0;
}
