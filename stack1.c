#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
int top=-1;
int s[MAX];
int overflow()
{
 if(top==MAX-1)
   return 1;
else
  return 0;
}
int  underflow()
{
if(top==-1)
 return 1;
else
 return 0;
}
void push(int *s,int ele)
{
  if(!overflow())
   {
     s[++top]=ele;
   }
  else
    printf("stack is full\n");
}
int pop(int *s)
 {
   if(!underflow())
    {
       return(s[top--]);
    }
  printf("stack is empty\n");
}
void display(int*s)
{
  int i;
  if(underflow())
   {
     printf("stack is empty\n");
     return;
   }
   printf("the content of the stack\n");
   for(i=0;i<=top;i++)
    printf("%d\n",s[i]);
}
void pallin()
{
char str[100];
printf("enter the string\n");
scanf("%s",str);
  int l = 0;
  int h = strlen(str) - 1;
  while (h > l)
  {
      if (str[l++] != str[h--])
      {
          printf("%s is Not Palindrome", str);
          return;
      }
  }
  printf("%s is palindrome", str);
}
void main ()
{
int ch,i,j,ele;
char str[20];
while(1)
{
  printf("\nenter the choice\n1.push\n2.pop\n3.display\n4.pallindrome\n5.exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:printf("enter the element to be pushed\n");
           scanf("%d",&ele);
           push(s,ele);
           break;
    case 2:ele=pop(s);
           if(ele!=0)
           printf("the popped element is %d",ele);
           break;
    case 3:display(s);
            break;
    case 4:pallin();
          break;
   case 5:exit(0);
}
}
}
