#include<stdio.h>
#include<string.h>

void main(){

char str[99];
char constant[]="const";
char var_name[10];
char var_value[10];
int position;
int i=0,j=0;

FILE *fp1,*fp2;
fp1=fopen("without_const.c","r");
fp2=fopen("with_const.c","w+");

while(fgets(str,99,fp1)!=NULL)
{
if((strstr(str,"int")!=NULL||strstr(str,"float")!=NULL||strstr(str,"char")!=NULL||strstr(str,"double")!=NULL)&&strstr(str,"=")!=NULL&&strstr(str,";")!=NULL)
{
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
	//fputs(var_name,fp2);
	}


	if(strstr(str,"=")!=NULL)
	{
	position=strstr(str,"=")-str;
	i=position+1;
	j=0;
	while(str[i]!=';')
	{
	var_value[j]=str[i];
	i++;
	j++;
	}
	//fputs(str,fp2);
	}
//fputs(str,fp2);
}
}

fseek(fp1,0,SEEK_SET);
while(fgets(str,99,fp1)!=NULL)
{
if((strstr(str,"int")!=NULL||strstr(str,"float")!=NULL||strstr(str,"char")!=NULL||strstr(str,"double")!=NULL)&&strstr(str," ")&&strstr(str,"=")!=NULL&&strstr(str,";")!=NULL)
{
	if(strstr(str,var_name)!=NULL&&(strstr(str,"=")==NULL||strstr(str,"++")==NULL||strstr(str,"--")==NULL))
	{
	fputs(constant,fp2);
	fputs(str,fp2);
	}
}
//fputs(str,fp2);
}

fclose(fp1);
fclose(fp2);
}
