#include<stdio.h>
#include<string.h>

void main(){

char str[99],str1[99];
char constant[]="const ";
char var_name[10];
char var_value[10];
int position,var_len,terminator=0,pos_seek;
int i=0,j=0;

FILE *fp1,*fp2;
fp1=fopen("userdata.c","r");
fp2=fopen("constant.c","w+");

while(fgets(str,99,fp1)!=NULL)
{
	if((strstr(str,"int")!=NULL||strstr(str,"float")!=NULL||strstr(str,"char")!=NULL||strstr(str,"double")!=NULL)&&strstr(str,"=")!=NULL&&strstr(str,";")!=NULL)
	{
		memset(var_name,0,10);
		terminator=1;
		if((strstr(str,"int")!=NULL||strstr(str,"float")!=NULL||strstr(str,"char")!=NULL||strstr(str,"double")!=NULL)&&strstr(str," ")!=NULL)
		{
			position=strstr(str," ")-str;
			i=position+1;
			j=0;
			while(str[i]!='=')
			{
				var_name[j]=str[i];
				i++;
				j++;
			}
			puts(var_name);
			var_len=strlen(var_name);
		}

		position=strstr(str,"=")-str;
		i=position+1;
		j=0;
		while(str[i]!=';')
		{
			var_value[j]=str[i];
			i++;
			j++;
		}
		puts(var_value);
		printf("var length is %d\n",var_len);

		pos_seek=ftell(fp1);
		while(fgets(str1,99,fp1)!=NULL)
		{		puts(str1);
 				if(strstr(str1,var_name)!=NULL&&(strstr(str,"=")!=NULL||strstr(str,"++")!=NULL||strstr(str,"--")!=NULL))
        			{
					puts("inside checking condition");
					position=strstr(str1,var_name)-str1;
					printf("position of pointer is %d\n",position);
					position=position+var_len;
					printf("str is ");
					puts(str1);
					if(str1[position]=='=' ||  (str1[position]=='+' && str1[position+1]=='+') || (str1[position]=='-' && str1[position+1]=='-'))
					{
						terminator=-1;
						break;
					}
        			}
		}
		fseek(fp1,pos_seek,SEEK_SET);
		if(terminator==0 || terminator==1)
		{
			fputs(constant,fp2);
			fputs(str,fp2);
		}
		else
			goto a;

	}
	else
	{
		a:
		fputs(str,fp2);
	}
}
fclose(fp1);
fclose(fp2);
}