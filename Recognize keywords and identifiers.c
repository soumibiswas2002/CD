#include<stdio.h>
#include<string.h>
int gflag=0;
int chckkwordfn(char [], int);
int isValid(char str[], int n)
{ 	int i;   
 if (!((str[0]>='a' && str[0]<='z')||(str[0]>='A' && str[0]<='Z') || str[0]=='_'))        	return 0;    
 for (i=1; i<n; i++) 	
{        if(!((str[i]>='a'&& str[i]<='z')||(str[i]>='A'&& str[i]<='Z')  || (str[i]>='0' && str[i]<= '9')|| str[i] == '_'))        	
return 0;    } 
return 1;}
int main()
{FILE *fi;
char c;
char str[30];
int i=0;
int flag=0;
int length=0;
fi=fopen("input2.c","r");	
while(1)	
{	c=fgetc(fi);	
if(c==EOF)	
break;	
else if((c=='\n')||(c=='\t')||(c==' ')||(c==';')||(c=='=')||(c=='[')||(c=='*')||(c==']')||(c=='('))
		{		
if(flag==0)			
{	continue;	}		
else if(flag==1)		
{	
str[i]='\0';			
i=0;			
flag=0;						
length=strlen(str);     			
if (isValid(str,length)==1)    			   	
{		
  if (!(chckkwordfn(str,length)))  
  	{printf("\nValid Identifier");   
   	printf(":%s\n", str);}    
 	}
       else
	//{//printf("\nInValid Identifier");
	//printf(":%s\n", str);}
continue;			
}		
}	
else{		
str[i++]=c;		
flag=1;		
continue;		
}	
}fclose(fi);
return 0;
}
int chckkwordfn(char s[], int l)
{char c;
int j=0;
int ind=0;
if(strlen(s)==0)	
return 0;
else{ 	c=s[0];
switch(c)
{case 'a':	
if(!strcmp(s,"auto"))	
ind=1;	
break;
case 'b':if(!strcmp(s,"break"))	
ind=1;	
break;
case 'c':if(!(strcmp(s,"continue")))	
ind=1;	
else if(!strcmp(s,"char"))	
ind=1;	
break;
case 'd':if(!strcmp(s,"do"))	
ind=1;	break;
case 'e':
if(!strcmp(s,"else"))	
ind=1;	
break;
case 'f':if(!(strcmp(s,"for")))	
ind=1;	
else if (!strcmp(s,"float"))	
ind=1;	
else if (!strcmp(s,"fopen"))	
ind=1;	
else if (!strcmp(s,"fclose"))	
ind=1;	
break;	
case 'p':if(!strcmp(s,"printf"))	
ind=1;	
break;
case 'i':if(!(strcmp(s,"if")))	
ind=1;	
else if (!strcmp(s,"int"))	
ind=1;	
break;
case 'r':if(!strcmp(s,"return"))	
ind=1;	
break;
case 's':if(!(strcmp(s,"struct")))	
ind=1;	
else if(!strcmp(s,"scanf"))	
ind=1;	
break;
case 'w':if(!strcmp(s,"while"))	
ind=1;	
break;
default:
ind=0;	
break;};
if(ind==1){	
printf("Keyword/ Function name: %s\n", s);	
gflag=1;	
return 1;}
else {gflag=0;return 0;}	
}return 0;}
