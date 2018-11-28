#include<stdio.h>
#include"exception.h"

int main()
{
int x=0;
initialize_exception();
try{
if(x<=0)
{
throw("Exception Raised",x);
}
}

catch(err)
{
fprintf(stderr,"Error %d:%s\n",err.code,err.msg);
}
end_try_catch
finalize_exception();
}
