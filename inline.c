#include<stdio.h>
#include<string.h>

void main(){

char str[99],word[30]={' '};									//word is defined to store a struct type return type
int i;
char *userdefined[5]={NULL,NULL,NULL,NULL,NULL};						//maximum of 5 different struct type return types
int pos,c=0;											//pos is used to find out the staring of struct key word in the line and counter 'c' is for words

FILE *fp1,*fp2;
fp1=fopen("userdata.c","r");
//fp2=fopen("inline.txt","w");

while(fgets(str,99,fp1)!=NULL)
{
        if(strstr(str,"struct")!=NULL)                 		 				//checking for struct beacuse it can also be a return type of a function
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
        }
	//for(i=0;i<=strlen(str)-1;i++)
	//{

	//}
}
}
