#include<stdio.h>
#include<string.h>

void main()
{
char str[99];												//to input the contents of userdata.c
char str1[99];												//to input the contents of contentloop.txt
char itr[10];												//to tkae the name of the the iterator in for loop eg. for(i=... here i is iterator & assuming 														iterator of loop to be maximum of 10 characters
char semic[20];												//to input the condition in the for loop
char sum_dec[3];											//to input whether the increment or decrement ++ or -- 
int cround_for_pos,c=0;											//variable to store the position of ) for inc/dec
int itr_pos,i,j,open=0,close=0,semic_pos;								//position variables
FILE *fp1,*fp2,*fp3;
fp1=fopen("userdata.c","r");										//opening userdata.c
fp2=fopen("loopunrolled.txt","w");
fp3=fopen("contentloop.txt","w+");									//file to input the content for loop

while(fgets(str,99,fp1)!=NULL)										//reading the file userdata.c
{
	if(strstr(str,"for(")!=NULL)									//checking the "for" loop in str
	{
		itr_pos=strstr(str,"(")-str;								//extracting the position of (
		i=itr_pos+1;
		j=0;
		while(str[i]!='=')									//to get the name of the iterator
		{
			c++;
			itr[j]=str[i];
			j++;
			i++;
		}
		semic_pos=strstr(str,";")-str;								//extracting the position of ;
		i=semic_pos+1;
		j=0;
		while(str[i]!=';')									//to get the name of iterator
		{
			semic[j]=str[i];
			j++;
			i++;
		}
		cround_for_pos=strstr(str,")")-str;							//extracting the position of (
		i=cround_for_pos-1;
		sum_dec[0]=str[i];									//finding whether ++ or --
		sum_dec[1]=str[(i-1)];									//finding whether ++ or --
		if(strstr(str,"{")!=NULL)								//checking for { in same line of for
		{	
			fputs(str,fp2);
			fgets(str,99,fp1);
			open++;
		}
		else											//checking for { in next line of for
		{	fgets(str,99,fp1);
			if(str[0]=='{')
			{	
				open++;
				fputs(str,fp2);
				fgets(str,99,fp1);
			}
		}

		b:											//putting the content of loop in different files and executing the for loop completely
                if(strstr(str,"{")!=NULL)                                                       	//checking for "{"
                {	
                        open++;
                }
                if(strstr(str,"}")!=NULL)                                                       	//checking for "}"
                {	
                        close++;
                        if((open-close)==0)                                                   		//if "{"-"}"=0 then it means for has ended
                        {	
                                goto a;                                                         	//therefore goto a i.e. end of for and out of for
                        }
                }
		fputs(str,fp3);
                fgets(str,99,fp1);                                                              	//putting the contents of str in contentloop.txt 
                goto b;                                                                         	//execute the same commands again

		a:
		fseek(fp3,0,SEEK_SET);									//seeking to the start of file contentloop.txt	
		while(fgets(str1,99,fp3)!=NULL)								//extracting file for 1st print
		{	
			fputs(str1,fp2);
		}
		fputs(itr,fp2);										//putting iterator in between
		fputs(sum_dec,fp2);
		fprintf(fp2,";");
		fprintf(fp2,"\n");
		fseek(fp3,0,SEEK_SET);
		while(fgets(str1,99,fp3)!=NULL) 							//extracting file for 2nd print in file
                {
                        fputs(str1,fp2);
                }
		fputs(str,fp2);										//putting last } of for

        }
	else												//if not for then just print the content
	{
		fputs(str,fp2);
	}
}

fclose(fp1);
fclose(fp2);
fclose(fp3);
}