#include<stdio.h>
#include"exception_handle.h"
#define mythrow int
int main()
{
int a,b,res;

void mytry()
{
res=a/b;
a=10;
b=0;
mythrow res;
printf("The result is=%d",res);
}

void catch(int res)
{
printf("Exception Caught/n Denominator can't be zero");
}

}
