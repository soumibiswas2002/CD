#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
int main()
{
FILE *fp;
int count=0;
char filename[MAX_FILE_NAME];
char c,ch;
printf("enter file name :");
scanf("%s",filename);
fp=fopen(filename,"r");
ch=EOF;
if(fp==NULL)
{
printf("could not open file %s",filename);
return 0;
}
for(c=getc(fp);c!=EOF;c=getc(fp))
{

if(c=='+')
{
  if(ch=='=')
  {
  count=count+1;printf("%C",c);c=getc(fp);
  }
  if(ch=='+')
  {
  count=count+1;printf("%C",c);c=getc(fp);
  }
  
 }
 if(c=='-')
{
  if(ch=='=')
  {
  count=count+1;printf("%C",c);c=getc(fp);
  }
  if(ch=='-')
  {
  count=count+1;printf("%C",c);c=getc(fp);
  } 
 }
 if(c=='=')
{
  if(ch=='=')
  {
    count=count+1;printf("%C",c);c=getc(fp);
    }
    }
    if(ch=='&')
{
  if(c=='&')
  {
    count=count+1;printf("%C",c);c=getc(fp);
    }
    }
    if(c=='|')
{
  if(ch=='|')
  {
    count=count+1;printf("%C",c);c=getc(fp);
    }
    }
 
 ch=c;
 printf("%C",c);
 }
 fclose(fp);
 printf("\n the file %s has %d characters\n",filename,count);
 return 0;
 }
