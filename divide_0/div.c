#include<stdio.h>
#define DENOMINATOR 1
int fun (int x)
{
if(x==0)
{
printf("Denominator can't be zero\n");
printf("Considering denominator as 1");
return DENOMINATOR;
}
else
return x;
}
