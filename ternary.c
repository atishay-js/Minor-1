#include<stdio.h>
#include<string.h>

void main(){

char str[99];
char str_nextline[99];
char str_nextline1[99];
int str_len;
char str_nosemi[99];
char str1[99];
char str2[99];
int open=0,close=0;
int pos_condition,i,j,coma_pos,pos_neg;
char condition[10]=" ";

FILE *fp1,*fp2,*fp3,*fp4,*fp5;
fp1=fopen("userdata.c","r");
fp2=fopen("ternary.txt","w+");
fp3=fopen("tern_if.txt","w+");
fp4=fopen("if_complete.txt","w+");
fp5=fopen("tern_else.txt","w+");

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
			if(strstr(str,";")!=NULL)
                	{
		        	str_len=strlen(str);
				memset(str_nosemi,0,str_len);
				j=0;
		                for(i=0;i<str_len-2;i++)
		                {
		                	str_nosemi[j]=str[i];
		                        j++;
		                }
			}
			if(strstr(str,"{")!=NULL)                                                       	//checking for "{" in the same line
                	{
                        	if(open==0)
					open++;
				else
				{
					open++;
					fputs(str_nosemi,fp3);
					fputs("\n",fp3);
				}
			}
                	else if(strstr(str,"}")!=NULL)                                                       	//checking for "}"
            		{
				close++;
                        	if((open-close)==0)                                                   		//if "{"-"}"=0 then it means for has ended
                        	{
					if(strstr(str,"else")!=NULL)
                			        goto b;								//else found in same line as }else
                                	break;                                                         		//therefore goto a i.e. end of for and out of for
                        	}
				fputs(str_nosemi,fp3);
				fputs("\n",fp3);
                	}
			else
			{
				fputs(str_nosemi,fp3);
				fputs("\n",fp3);
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
		fseek(fp3,0,SEEK_SET);
                fgets(str_nextline,99,fp3);
		j=0;
                while(strstr(str_nextline1,"~")==NULL)
                {
                        fgets(str_nextline1,99,fp3);
			if(strstr(str_nextline1,"~")==NULL)
                        {
                                j=j+strlen(str_nextline);
                               	memset(str_nextline,0,99);
                                fseek(fp3,j-1,SEEK_SET);
                                fputs(",",fp3);
                                fseek(fp3,j+strlen(str_nextline1),SEEK_SET);
                                strcpy(str_nextline,str_nextline1);
			}
                        else
                                break;
                }
		fseek(fp3,0,SEEK_END);
		do
                {
			if(strstr(str,";")!=NULL)
                	{
		        	str_len=strlen(str);
				memset(str_nosemi,0,str_len);
				j=0;
		                for(i=0;i<str_len-2;i++)
		                {
		                	str_nosemi[j]=str[i];
		                        j++;
		                }
				//str_nosemi[j]=',';
				//puts(str_nosemi);
              		}
                        if(strstr(str,"{")!=NULL)                                                               //checking for "{"
                        {
                                if(open==0)
                                        open++;
                                else
                                {
                                        open++;
                                        fputs(str_nosemi,fp5);
					fputs("\n",fp5);
                                }
                        }
                        else if(strstr(str,"}")!=NULL)                                                               //checking for "}"
                        {
                                close++;
                                if((open-close)==0)                                                             //if "{"-"}"=0 then it means for has ended
                                {
                                       break;                                                          		//therefore goto a i.e. end of for and out of for
                                }
                                fputs(str_nosemi,fp5);
				fputs("\n",fp5);
                        }
                        else
                        {
                                fputs(str_nosemi,fp5);
				fputs("\n",fp5);
			}
                        fgets(str,99,fp1);
			//if(strstr(str,"}")==NULL || (open-(close+1))!=0)
			//	fputs(",",fp3);
                }while((open-close)!=0);
		fputs("~\n",fp5);
		fseek(fp5,0,SEEK_SET);
		memset(str_nextline1,0,99);
                fgets(str_nextline,99,fp5);
                j=0;
                while(strstr(str_nextline1,"~")==NULL)
                {
                        fgets(str_nextline1,99,fp5);
                        if(strstr(str_nextline1,"~")==NULL)
                        {
                                j=j+strlen(str_nextline);
                                memset(str_nextline,0,99);
                                fseek(fp5,j-1,SEEK_SET);
                                fputs(",",fp5);
                                fseek(fp5,j+strlen(str_nextline1),SEEK_SET);
                                strcpy(str_nextline,str_nextline1);
                        }
                        else
                                break;
                }
		fseek(fp5,0,SEEK_END);

		fputs(condition,fp2);
		fputs("?(",fp2);
		fseek(fp3,0,SEEK_SET);
		while(fgets(str2,99,fp3)!=NULL)
		{
			if(strstr(str2,"~")!=NULL)
				break;
			fputs(str2,fp2);
		}
		fputs("):\n(",fp2);
		fseek(fp5,0,SEEK_SET);
		while(fgets(str2,99,fp5)!=NULL)
		{
			if(strstr(str2,"~")!=NULL)
				break;
			fputs(str2,fp2);
		}
		fputs(");\n",fp2);
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
