#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main(){

char str[99],word[30]={' '};
char inlne[]="inline ";										//word is defined to store a struct type return type
int i;
char openr=(char)40;
char space[]=" ";
char opencurl[]="{",openround[]="(",closeround[]=")";
char *userdefined[5]={NULL,NULL,NULL,NULL,NULL};						//maximum of 5 different struct type return types
int pos,c=0,openc=0,closec=0;									//pos is used to find out the staring of struct key word in the line and counter 'c' is for words

FILE *fp1,*fp2;
fp1=fopen("userdata.c","r");
fp2=fopen("inline.txt","w");

while(fgets(str,99,fp1)!=NULL)
{
        /*if(strstr(str,"struct")!=NULL)                 		 			//checking for struct beacuse it can also be a return type of a function
        {
		char *chr=word;									//defining here because chr will refer to updater word
       		pos = strstr(str,"struct")-str;							//to fing out position og struct in line
                for(i=pos+7;i<=strlen(str)-1;i++)						//stating i from i+7 beacuse struct and space counts to 7
		{
			if(str[i]!='{')								//accepting word
				*chr++=str[i];
			else									//termination
				break;
		}
		userdefined[c]=word;								//assigning word
		c++;										//for next word
		strcpy(word," ");								//initializing word as empty again
        }*/
	if(strstr(str,"main(")!=NULL)								//to check for main in usercode
	{
		b:
		if(strstr(str,"{")!=NULL)							//checking for "{"
		{
			openc++;
		}
		if(strstr(str,"}")!=NULL)							//checking for "}"
		{
			closec++;
			if((openc-closec)==0)							//if "{"-"}"=0 then it means main has ended
			{
				goto a;								//therefore goto a i.e. end of main and out of main
			}
		}
		fputs(str,fp2);
		fgets(str,99,fp1);								//if still in main 
		goto b;										//execute the same commands again
		a:	;									/*In the standard it's explicitly said that labels belong to a statement, therefore a 
												simple semicolon (;) after your label can circumvent the problem you are running in to, 
												since that counts as a statement.*/
		fputs(str,fp2);									//putting the termination "}" line
		fgets(str,99,fp1);								//TO EXIT OUT OF MAIN COMPLETELY
	}
	if(strstr(str,space)!=NULL && strstr(str,openround)!=NULL && strstr(str,closeround)!=NULL)	//checking for condition for function which is defined outside main
													//and is met by checking for (,) and " " in string
	{
		for(i=0;i<=strlen(str)-1;i++)
               	{
			if(isalnum(str[i]) && str[i+1]==openr)					//conforming function by s(
			{
				fputs(inlne,fp2);						//putting inline keyword in the file before function name
			}
 		}
	}
	fputs(str,fp2);										//to put the contents of the file after inline is put
}


fclose(fp1);
fclose(fp2);
}
