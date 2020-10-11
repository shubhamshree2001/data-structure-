#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int create(int num)
{
  int key;
  key=num%100;
  return key;
}
void display(int a[MAX])
{
int i;
printf("the hash table is\n");
printf("key/index \t employee id\n");
printf("\n");
for(i=0;i<MAX;i++)
 printf("\n%d \t %d\n",i,a[i]);
}
void linearprob(int a[MAX],int key,int num)
{
  int flag=0,i,count=10;
  if(a[key]==-1)
  {
    a[key]=num;
  }
  else
  {
    for (i=10;i<MAX;i++)
    {
      if(a[i]!=-1)
        count++;
    }
  if(count==MAX)
   {
      printf("hash table is full\n");
      display(a);
      exit(1);
    }
    else
    {
     for(i=key+1;i<MAX;i++)
     {
       if(a[i]==-1)
        {
           a[i]=num;
           flag=1;
           break;
        }
     }
        for(i=10;i<key&&flag==0;i++)
        {
         if(a[i]==-1)
         {
            a[i]=num;
            flag=1;
            break;
         }
    }
  }
}
}
int main()
{
  int a[MAX],num,key,i,ans;
  for(i=0;i<MAX;i++)
    a[i]=-1;
  do
  {
    printf("\n enter four digit number" );
    scanf("%d",&num);
    key=create(num);
    linearprob(a,key,num);
    printf("do you want to continue?\n");
    scanf("%d",&ans);
  }
  while(ans==1);
  display(a);
}
