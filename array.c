#include<stdio.h>
#include<stdlib.h>
int n;
void read(int a[10])
{
int i;
printf("enter the element in the array\n");
for(i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}
}
void  print(int a[10])
{
int i;
printf("the elements are\n");
for(i=0;i<n;i++)
printf("%d",a[i]);
}
void insert(int a[10],int ele,int pos)
{
int i;
for(i=n-1;i>=pos-1;i--)
{
  a[i+1]=a[i];
}
  a[pos-1]=ele;
  n++;
}
int delete(int a[10],int pos)
{
  int i,ele;
  ele=a[pos-1];
  for(i=pos-1;i<n-1;i++)
  {
    a[i]=a[i+1];
    n--;
  }
  return ele;
}
void main()
{
 int a[10],ch,ele,pos;
  while(1)
    {
      printf("\n 1.read\n2.print\n3.insert\n4.delete\n5.exit\n");
      printf("slect an option\n");
      scanf("%d",&ch);
      switch(ch)
        {
          case 1: printf("enter the n\n");
                  scanf("%d",&n);
                  read(a);
                  break;
          case 2:print(a);
                 break;
          case 3: printf("enter the element and position\n");
                  scanf("%d%d",&ele,&pos);
                  insert(a,ele,pos);
                  break;
         case 4: printf("enter the position\n");
                 scanf("%d",&pos);
                 ele=delete(a,pos);
                 printf("deleted element=%d\n",ele);
                 break;
        default: exit(0);
        }
   }
}
