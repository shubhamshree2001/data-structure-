#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void read(char*s)
{
 gets(s);
}
void stringcopy(char*s1,char*s2)
{
  int i;
    for(i=0;s2[i]!='\0';i++)
    {
      s1[i]=s2[i];
      s1[i]='\0';
    }
}
int matchreplace(char*str,char*pat,char*rep)
{
  char ans[100];
  int i=0,m=0,c=0,j=0,flag=0,k;
  while(str[c]!='\0')
  {
   if(str[m]==pat[i])
   {
     i++;
     m++;
    if(pat[i]=='\0')
   {
     flag=1;
     for(k=0;rep[k]!='\0';k++,j++)
        ans[j]=rep[k];
        i=0;
        c=m;
    }
  }
      else
    {
       ans[j]=str[c];
       j++;
       c++;
       m=c;
       i=0;
    }
  }
  ans[j]='\0';
  stringcopy(str,ans);
  return flag;
}
int main()
{
char str[100],pat[100],rep[100];
int flag=0;
printf("enter the string\n");
read(str);
printf("enter the pattern\n");
read(pat);
printf("enter the string to be replaced\n");
read(rep);
flag=matchreplace(str,pat,rep);
if(flag==1)
{
  printf("the string is found%s",str);
}
else
  {
     printf("the pattern is not found\n");
  }
return 0;
}
