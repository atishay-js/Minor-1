#include<stdio.h>
int main()
{
int a,b;
inlining(a,b);
}
int inlining(a,b)
{
a=a-b;
b++;
a = a*b;
return a;
}
// Optimization commands
//1.) -finline-functions
//2.) -O1,-O2,-O3
//3.) -Os, -Ofast
