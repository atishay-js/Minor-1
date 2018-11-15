#include<stdio.h>
#include<string.h>

void main()
{
char str[99],str1[99];
char itr[10],semic[20];											//assuming iterator of loop to be maximum of 10 characters
int itr_pos,i,j,open=0,close=0,semic_pos;
FILE *fp1,*fp2,*fp3;
fp1=fopen("userdata.c","r");
fp2=fopen("loopunrolled.txt","w");
fp3=fopen("contentloop.txt","w+");

while(fgets(str,99,fp1)!=NULL)
{
	if(strstr(str,"for(")!=NULL)
	{	puts("identified for");
		itr_pos=strstr(str,"(")-str;
		i=itr_pos+1;
		j=0;
		puts(str);
		printf("%d\n",i);
		while(str[i]!='=')
		{	puts("identified iterator");
			itr[j]=str[i];
			j++;
			i++;
		}
		semic_pos=strstr(str,";")-str;
		i=semic_pos+1;
		j=0;
		while(str[i]!=';')
		{
			semic[j]=str[i];
			j++;
			i++;
		}
		printf("Iterator is %s\n",itr);
                if(strstr(str,"{")!=NULL)
		{	puts("checking opening curly brace in same line");
			fputs(str,fp2);
			fgets(str,99,fp1);
			open++;
		}
		else
		{	puts("checking opening curly brace in next same line");
			fgets(str,99,fp1);
			if(str[0]=='{')
			{	puts("checking closing curly brace in same line");
				open++;
				fputs(str,fp2);
				fgets(str,99,fp1);
			}
		}

		b:
		puts("inside for");
                if(strstr(str,"{")!=NULL)                                                       //checking for "{"
                {	puts("checking { in for");
                        open++;
                }
                if(strstr(str,"}")!=NULL)                                                       //checking for "}"
                {	puts("checking } in for");
                        close++;
                        if((open-close)==0)                                                   //if "{"-"}"=0 then it means main has ended
                        {	puts("checking termination condition");
                                goto a;                                                         //therefore goto a i.e. end of main and out of main
                        }
                }
		puts("puting str in fp3");
		puts(str);
                fputs(str,fp3);
                fgets(str,99,fp1);                                                              //if still in main 
                goto b;                                                                         //execute the same commands again

		a:
		fseek(fp3,0,SEEK_SET);
		while(fgets(str1,99,fp3)!=NULL)
		{	puts("putting for contents into  file");
			fputs(str1,fp2);
		}
		fputs(itr,fp2);
		fputs("++;",fp2);
		fprintf(fp2,"\n");
		fseek(fp3,0,SEEK_SET);
		while(fgets(str1,99,fp3)!=NULL) 
                {
                        fputs(str1,fp2);
                }
		fputs(str,fp2);

        }
	else
	{
		fputs(str,fp2);
	}
}



fclose(fp1);
fclose(fp2);
fclose(fp3);
}
