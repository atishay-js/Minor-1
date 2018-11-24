#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main(){

char str[99];
int i,j,c=0;
char space=(char)32;									//to print space in the file
char nextline=(char)10;									//to print nextline
char backslash=(char)92;
char n=(char)110;

FILE *fp1,*fp2;
fp1=fopen("userdata.c","r");
fp2=fopen("optimized.txt","w");

while(fgets(str,99,fp1)!=NULL)								//to extract userdata.c line by line
{
	if(str[0]=='\n')
		goto a;
	for(i=0;i<strlen(str)-1;i++)
	{
		//if(strstr(str,nextline))
		//{
		//	break;
		//}
		if(!isspace(str[i]) && !isspace(str[i+1]))	 			 //case when there are continous characters and not any space in between ab,#a,##,b#
                {
                        fputc(str[i],fp2);
                }
		else if(isalnum(str[i]) && isspace(str[i+1]))				//case when there is an alphabet and then space
		{
			fputc(str[i],fp2);
			for(j=i+2;j<=strlen(str)-1;j++)
			{
				if(isalnum(str[j]))					//for case eg int       a
				{
					fputc(space,fp2);
					fputc(str[j],fp2);
					i=j;
					break;
				}
				else if(!isspace(str[j]) && !isalnum(str[j]))		//for case eg a         +
				{
					fputc(str[j],fp2);
					i=j;
					break;
				}
			}
		}
		else if((!isalnum(str[i]) && !isspace(str[i])) && isspace(str[i+1]))
		{
			fputc(str[i],fp2);
			for(j=i+1;j<=strlen(str)-1;j++)
                        {
                                if(isalnum(str[j]))                                     //for case eg +       a
                                {
                                        fputc(str[j],fp2);
					i=j;
                                        break;
                                }
                                else if(!isspace(str[j]) && !isalnum(str[j]))           //for case eg +         =
                                {
                                        fputc(str[j],fp2);
					i=j;
                                        break;
                                }
                        }
		}
	}
	fputc(nextline,fp2);
	a:  ;
}
fclose(fp1);
fclose(fp2);
}