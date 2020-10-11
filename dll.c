#include<stdio.h>
#include<stdlib.h>
struct node
{
 char ssn[10];
 char name[10];
 char dept[10];
 char des[10];
 char sal[10];
 char phone[10];
 struct node *rlink;
 struct node *llink;
};
typedef struct node *node;
node head=NULL;
node createnode()
{
  node temp;
 temp=malloc(sizeof(struct node));
 printf("enter the ssn\n");
 scanf("%s",temp->ssn);
 printf("enter the name\n");
 scanf("%s",temp->name);
 printf("enter the department\n");
 scanf("%s",temp->dept);
 printf("enter the designation\n");
 scanf("%s",temp->des);
 printf("enter the sal\n");
 scanf("%s",temp->sal);
 printf("enter the phone\n");
 scanf("%s",temp->phone);
 temp->rlink=NULL;
 temp->llink=NULL;
 return temp;
}
void insertfront()
{
  node dll;
  dll=createnode();
  if(head!=NULL)
  {
    dll->rlink=head;
    head->llink=dll;
  }
  head=dll;
}
void insertend()
{
  node dll,temp=head;
  dll=createnode();
  if(head==NULL)
   head=dll;
 else
  {
    while(temp->rlink!=NULL)
    {
      temp=temp->rlink;
    }
    temp->rlink=dll;
    dll->llink=temp;
  }
}

void create()
{
  int n,i;
  printf("enter the no. of employee\n");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
   insertend();
 }
void deletefront()
{
  node dll=head;
  printf("the deleted node is\n");
  printf(" the ssn%s\n",dll->ssn);
  printf("the name %s\n",dll->name);
  printf("the department%s\n",dll->dept);
  printf(" the designation%s\n",dll->des);
  printf(" the sal%s\n",dll->sal);
  printf("the phone%s\n",dll->phone);
  head=dll->rlink;
  head->llink=NULL;
  free(dll);
}
void deleteend()
{
  node temp=head,t;
  if(head==NULL)
    printf("list is empty\n");
  else
  {
    while(temp->rlink!=NULL)
    {
      t=temp;
      temp=temp->rlink;
    }
    printf("the deleted node is\n");
    printf(" the ssn%s\n",temp->ssn);
    printf("the name %s\n",temp->name);
    printf("the department%s\n",temp->dept);
    printf(" the designation%s\n",temp->des);
    printf(" the sal%s\n",temp->sal);
    printf("the phone%s\n",temp->phone);
    free(temp);
    t->rlink=NULL;
  }
}
void display()
{
  int c=0;
  node temp=head;
  while(temp!=NULL)
  {
    printf(" the ssn%s\n",temp->ssn);
    printf("the nameb%s\n",temp->name);
    printf("the department%s\n",temp->dept);
    printf(" the designation%s\n",temp->des);
    printf(" the sal%s\n",temp->sal);
    printf("the phone%s\n",temp->phone);
    temp=temp->rlink;
    c++;
  }
  printf("the no. of nodes is %d\n",c);
}
void dequeue()
{
int choice;
  printf("\nenter the choice\n1.insert at front\n2.insert at rear\n3.delete from front\n4.delete from rear\n");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:printf("enter the details to be inserted\n");
         insertfront();
         break;
  case 2:printf("enter the details to be inserted\n");
         insertend();
         break;
  case 3:printf("the deleted node is\n");
         deletefront();
         break;
  case 4:printf("the deleted node is\n");
         deleteend();
         break;
}
}
int main()
{
  int ch;
  while(1)
  {
    printf("\nenter your choice\n1.create\n2.insert front\n3.delete front\n4.insert end\n5.delete end\n6.display\n7.deque\n8.exit\n");
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
      case 7:dequeue();
              break;
    }
  }
  return 0;
}
