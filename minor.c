#include<stdio.h>

int system(const char *);				// //to invoke any operating system commands
char s[100];

void input_user();					//input function
void predict();						//to predict errors and warnings
void print_file(char *);				//to display the contents of various log files
void output();						//to display the output of the user code

int main(){
input_user();						//calling input function
predict();						//calling the predict function
return 0;
}

void input_user(){					//to input user code
FILE *fp;						//input will be stored in a .c file
fp=fopen("userdata.c","w");
while(scanf("%[^~]",s)==1){				//for taking multi line input  and fusing "~" as delimiter
fprintf(fp,"%s",s);					//for writing the input in the file
}
fclose(fp);
}

void predict(){
system("gcc userdata.c 2> logsgcc.txt -o userdata");
system("cppcheck userdata.c 2> logcpp.txt");
system("splint userdata.c -streamoverwrite +message-stream logssplintmsg.txt +warning-stream logssplintwarn.txt +error-stream logsplinterr.txt");

printf("\nCompilation error:\n");
print_file("logsgcc.txt");				//Function to print log file created by gcc compiler
printf("\nIn a easy way:\n");
print_file("logsplinterr.txt");				//Function to print error-log file by splint

printf("\nCode improvemnets: \n");
print_file("logssplintwarn.txt");			//Function to print warning-log file by splint

printf("\nError Predictions: \n");
print_file("logcpp.txt");				//function to print log file by cppcheck

printf("\nAny extra remarks: \n");
print_file("logssplintmsg.txt");			//function to print any extra warnings

}

void print_file(char *name){
FILE *fp;
fp=fopen(name,"r");
while(fgets(s,99,fp)!=NULL){
printf("%s",s);
}
fclose(fp);
}

void output(){						//to output the user code
system("./userdata");
}
