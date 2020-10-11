#include<stdio.h>
#include<stdlib.h>
#define MAX 5
char cq[MAX],f=-1,r=-1;
int cqfull()
{
 if((f==r+1)||(f==0&&r==MAX-1))
  return 1;
  return 0;
}
int cqempty()
{
 if(f==-1)
  return 1;
  return 0;
}
char cqinsert(char ele)
{
 if(cqfull())
  printf("overflow\n");
 else
 {
   if(f==-1)
    f=0;
    r=(r+1)%MAX;
    cq[r]=ele;
 }
}
char cqdelete()
{
  char ele;
  if(cqempty())
  {
    printf("underflow\n");
    return(-1);
  }
  else
  {
    ele=cq[f];
    if(f==r)
     {
       f=-1;
       r=-1;
     }
  else
    f=(f+1)%MAX;
    return (ele);
}
}
void display()
{
  int i;
  if(cqempty())
  {
    printf("empty queue\n");
  }
  else
  {  
    for(i=f;i!=r;i=(i+1)%MAX)
     printf("%c",cq[i]);
    printf("%c",cq[i]);
      }
}
int main()
{
 int option;
 char ele;
 while(1)
 {
   printf("\n enter your choice\n1.insert\n2.delete\n3.display\n4.exit\n");
   scanf("%d",&option);
   switch(option)
   {
    case 1:printf("enter element to be inserted\n");
             scanf("%s",&ele);
             cqinsert(ele);
             break;
    case 2:ele=cqdelete();
           if(ele!=-1)
             printf("deleted element is %c",ele);
             break;
    case 3:printf("circular queueis\n");
           display();
           break;
    case 4:exit(0);
   }
 }
 return 0;
}
