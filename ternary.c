#include<stdio.h>
#include<string.h>

void main(){

char str[99];
char str1[99];
char str2[99];
int open=0,close=0;
int pos_condition,i,j;
char condition[10]=" ";

FILE *fp1,*fp2,*fp3,*fp4;
fp1=fopen("userdata.c","r");
fp2=fopen("ternary.txt","w+");
fp3=fopen("tern_content.txt","w+");
fp4=fopen("if_complete.txt","w+");

while(fgets(str,99,fp1)!=NULL)
{
	if(strstr(str,"if(")!=NULL)
	{
		pos_condition=strstr(str,"(")-str;
		i=pos_condition+1;
		j=0;
		while(str[i]!=')')
		{
			condition[j]=str[i];
			i++;
			j++;
		}
		do
		{
			fputs(str,fp4);
			if(strstr(str,"{")!=NULL)                                                       	//checking for "{" in the same line
                	{
                        	if(open==0)
					open++;
				else
				{
					open++;
					fputs(str,fp3);
				}
			}
                	else if(strstr(str,"}")!=NULL)                                                       	//checking for "}"
            		{
				close++;
                        	if((open-close)==0)                                                   		//if "{"-"}"=0 then it means for has ended
                        	{
					if(strstr(str,"else")!=NULL)
                			        goto b;								//else found in same line as }else
                                	break;                                                         	//therefore goto a i.e. end of for and out of for
                        	}
				fputs(str,fp3);
                	}
			else
			{
				fputs(str,fp3);
			}
			fgets(str,99,fp1);
		}while((open-close)!=0);
		fgets(str,99,fp1);
		if(strstr(str,"else")!=NULL)
		{
			goto b;
		}
		else
		{
			goto c;											//else not found
		}
		b:
		open=0;
		close=0;
		fputs("~\n",fp3);
		do
                {
                        if(strstr(str,"{")!=NULL)                                                               //checking for "{"
                        {
                                if(open==0)
                                        open++;
                                else
                                {
                                        open++;
                                        fputs(str,fp3);
                                }
                        }
                        else if(strstr(str,"}")!=NULL)                                                               //checking for "}"
                        {
                                close++;
                                if((open-close)==0)                                                             //if "{"-"}"=0 then it means for has ended
                                {
                                       break;                                                          		//therefore goto a i.e. end of for and out of for
                                }
                                fputs(str,fp3);
                        }
                        else
                        {
                                fputs(str,fp3);
                        }
                        fgets(str,99,fp1);
                }while((open-close)!=0);
		fputs(condition,fp2);
		fputs("?",fp2);
		fseek(fp3,0,SEEK_SET);
		while(fgets(str2,99,fp3)!=NULL)
		{
			if(strstr(str2,"~")!=NULL)
				break;
			fputs(str2,fp2);
		}
		fputs(":\n",fp2);
		while(fgets(str2,99,fp3)!=NULL)
		{
			fputs(str2,fp2);
		}
		fputs(";\n",fp2);
		c:
		while(fgets(str1,99,fp4)!=NULL)
		{
			fputs(str1,fp2);
		}
	}
	else
	{
		fputs(str,fp2);
	}
}

fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
}




















/*










do{
	condition=fputs(str,fp2);
	}
	while(strstr(str,")")!=NULL);

	for(strstr(str,"{")!=NULL;strstr(str,"}")!=NULL;str++)
	{
	state1=fputs(str,fp2);
	}

	}

	if(strstr(str,"else")
*/
