#include <stdio.h>
#include "exception.h"

int main(int argc, char **argv) {
	exception_init();
	try
		printf("Ok!\n");
		throw("An error happened", 1);
		printf("Super Ok!\n");
	catch(err)
		fprintf(stderr, "Error %d: %s\n", err.code, err.msg);
	end_try_catch
	exception_end();
	return 0;
}