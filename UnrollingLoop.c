#include<stdio.h>
void main()
{
unsigned int n;
int i;
char ch;
printf("Enter N\n");
scanf("%u",&n);
printf("\n1. Loop Roll\n2. Loop Unroll 2\n3. Loop Unroll 3\n4. Loop Unroll 4\n5. Loop Unroll 5\n");
printf("\nEnter your choice\n");
scanf(" %c",&ch);
switch(ch)
{
case '1':
  i=loop1(n);
  printf("\nLoop Roll: Count of  1's    :  %d" ,i);
  break;
case '2':
  i=loop2(n);
  printf("\nLoop Unroll 2:  Count of 1's  :  %d" ,i);
  break;
case '3':
  i=loop3(n);
  printf("\nLoop Unroll 3:  Count of 1's  :  %d" ,i);
  break;
case '4':
  i=loop4(n);
  printf("\nLoop Unroll 4:  Count of 1's  :  %d" ,i);
  break;
case '5':
  i=loop5(n);
  printf("\nLoop Unroll 5:  Count of 1's  :  %d" ,i);
  break;
default:
  printf("\n Wrong Choice\n");

}
}
int loop1(unsigned int n)
{
    int  j=0,k=0;
    while (n != 0)
    {
 if (n & 1) j++;
 n >>= 1;
 k++;
    }
    printf("\n no of iterations  %d",k);
    return j;
}
int loop2(unsigned int n)
{
    int  j=0,k=0;
    while (n != 0)
    {
 if (n & 1) j++;
 if (n & 2) j++;
 n >>= 2;
 k++;
    }
    printf("\n no of iterations  %d",k);
    return j;
}
int loop3(unsigned int n)
{
    int j=0,k=0;
    while (n != 0)
    {
 if (n & 1) j++;
 if (n & 2) j++;
 if (n & 4) j++;
 n >>= 3;
 k++;
    }
    printf("\n no of iterations  %d",k);
    return j;
}
int loop4(unsigned int n)
{
    int k=0,j=0;
    while (n != 0)
    {
 if (n & 1) j++;
 if (n & 2) j++;
 if (n & 4) j++;
 if (n & 8) j++;
 n >>= 4;
 k++;
    }
    printf("\n no of iterations  %d",k);
    return j;
}
int loop5(unsigned int n)
{
    int j=0,k=0;
    while (n != 0)
    {
 if (n & 1) j++;
 if (n & 2) j++;
 if (n & 4) j++;
 if (n & 8) j++;
 if (n & 16) j++;
 n >>= 5;
 k++;
    }
    printf("\n no of iterations  %d",k);
    return j;
}
