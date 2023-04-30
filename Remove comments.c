#include <stdio.h>
#include <stdlib.h>
int main()
{    FILE *fp1,*fp2;   
 int flag=0;   
 char ch;    
fp1=fopen("input2.c","r");    
fp2=fopen("outputrc.c","w");    
if(fp1==NULL)    
{        
  printf("Error while opening a file for reading");        
  return 0;
}
if(fp2==NULL)   
{ 
  printf("Error while opening a file for writing");        
  return 0;
}
while((ch=fgetc(fp1))!=EOF)    
	{         
	if((ch=='/')&&(flag==0))        
		{   flag=1;           
		 continue;        }        
	else if((ch=='/')&&(flag==1))       
 		{            flag=2;           
		 continue;        }        
	else if((ch=='*')&&(flag==1))       
		 {            flag=3;          
  		continue;        }        
	if(flag==2)       
 	{            if(ch=='\n')           
 		{              flag=0; }           
	 continue;}
  if(flag==3)        
	{            if(ch=='*')            
		{              flag=4;            }           
 	continue;        }       
 	if(flag==4)        
	{            if(ch=='/')           
 		{              flag=0;            }         
   	continue;  
	}      
	if(flag==0)        
	{             fputc(ch,fp2);           }   
 	}   
 fclose(fp1);   
 fclose(fp2);
 fp1=fopen("outputrc.c","r");    
while((ch=fgetc(fp1))!=EOF)    
	{        printf("%c",ch);    }   
 fclose(fp1);   
 return 0;}



