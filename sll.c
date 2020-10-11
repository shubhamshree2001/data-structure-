#include<stdio.h>
#include<stdlib.h>
struct node
{
 char usn[10];
 char name[10];
 char branch[10];
 char sem[10];
 char phone[10];
 struct node *link;
};
typedef struct node *node;
node head=NULL;
node createnode()
{
  node temp;
  temp=malloc(sizeof(struct node));
  printf("enter the usn\n");
  scanf("%s",temp->usn);
  printf("enter the name\n");
  scanf("%s",temp->name);
  printf("enter the branch\n");
  scanf("%s",temp->branch);
  printf("enter the sem\n");
  scanf("%s",temp->sem);
  printf("enter the phone\n");
  scanf("%s",temp->phone);
  temp->link=NULL;
  return temp;
}
void insertfront()
{
  node sll;
  sll=createnode();
  if(head!=NULL)
   sll->link=head;
  head=sll;
}
void insertend()
{
  node sll,temp=head;
  sll=createnode();
  if(head==NULL)
   head=sll;
  else
  {
  while(temp->link!=NULL);
    temp=temp->link;
  temp->link=sll;
  }
}
void create()
{
  int n,i;
  printf("enter the no. of students\n");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
   insertend();
}
void deletefront()
{
  node sll=head;
  printf("the deleted node is\n");
  printf("usn=%s\n",sll->usn);
  printf("name=%s\n",sll->name);
  printf("branch=%s\n",sll->branch);
  printf("sem=%s\n",sll->sem);
  printf("phone=%s\n",sll->phone);
  head=sll->link;
  free(sll);
}
void deleteend()
{
  node temp=head;
  node t;
    if(head==NULL)
    printf("link lisst is empty\n");
    else
    {
      while(temp->link!=NULL)
      {
          t=temp;
          temp=temp->link;
      }
      printf("the deleted node is\n");
      printf("usn=%s\n",temp->usn);
      printf("name=%s\n",temp->name);
      printf("branch=%s\n",temp->branch);
      printf("sem=%s\n",temp->sem);
      printf("phone=%s\n",temp->phone);
    }
  free(t->link);
  t->link=NULL;
}
void display()
{
  int c=0;
  node temp=head;
  while(temp!=NULL)
  {
    printf("usn=%s\n",temp->usn);
    printf("name=%s\n",temp->name);
    printf("branch=%s\n",temp->branch);
    printf("sem=%s\n",temp->sem);
    printf("phone=%s\n",temp->phone);
    temp=temp->link;
    c++;
  }
  printf("the no. of node is%d",c);
}
void stack()
{
  int choice;
  printf("\nenter your choice\n1.push\n2.pop\n3.display\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:printf("\nenter element in stack\n");
           insertfront();
           break;
    case 2:printf("\nthe element poped is\n");
           deletefront();
           break;
    case 3:printf("the stack is\n");
          display();
          break;
  }
}
int main()
{
int ch;
  while(1)
  {
    printf("\nenter your choice\n1.create\n2.insert front\n3.delete front\n4.insert end\n5.delete end\n6.display\n7.stack\n8.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:create();
             break;
      case 2:insertfront();
              break;
      case 3:deletefront();
              break;
      case 4:insertend();
              break;
      case 5:deleteend();
              break;
      case 6:display();
              break;
      case 7:stack();
              break;
    }
  }
  return 0;
}
