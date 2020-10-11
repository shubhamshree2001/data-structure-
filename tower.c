#include<stdio.h>
void move(int n,char source,char spare,char dest)
{
 if(n==1)
 {
  printf("\nmove from %c to %c",source ,dest);
 }
 else
 {
  move(n-1,source,dest,spare);
  printf("move from %c to %c ",source,dest);
  move(n-1,spare,source,dest);
 }
}
int main()
{
int n;
printf("enter the no. of disk\n");
scanf("%d",&n);
move(n,'a','b','c');
return 0;
}
