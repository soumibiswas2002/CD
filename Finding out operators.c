#include<stdio.h>
/*#include<conio.h>*/
int main(){   
FILE *fp;   
char ch, fname[30];  
 int noOfOp=0;   printf("Enter file name with extension: ");  
 scanf("%s", fname); 
   fp = fopen(fname, "r");  
 while(fp)   
{      ch = fgetc(fp);      
if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='%'))
 break;      
noOfOp++;        
 }   
fclose(fp);  
 printf("\nNumber of operators = %d\n", noOfOp);      
   return 0;}
