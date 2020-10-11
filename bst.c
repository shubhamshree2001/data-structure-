#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *left;
 struct node *right;
};
struct node *createnode(int item)
{
  struct node *temp=(struct node *)malloc(sizeof(struct  node));
  temp->data=item;
  temp->left=temp->right=NULL;
  return temp;
}
struct node *insert(struct node *node,int key)
{
  if(node==NULL)
  return createnode(key);
  if(key<node->data)
   node->left=insert(node->left,key);
  else if(key>node->data)
    node->right=insert(node->right,key);
  return node;
}
int search(struct node *root, int key)
{
  if(root==NULL)
   return -1;
  if(root->data==key)
    return 1;
  if(root->data<key)
    return search(root->right,key);
  return search(root->left,key);
}
void inorder(struct node*root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
  }
}
void preorder(struct node *root)
{
  if(root!=NULL)
  {
   printf("%d\t",root->data);
   preorder(root->left);
   preorder(root->right);
  }
}
void postorder(struct node *root)
{
  if(root!=NULL)
   {
     postorder(root->left);
     postorder(root->right);
     printf("%d\t",root->data);
   }
}
int main()
{
 int n,i,ch,key,pos;
 struct node *root=NULL;
 while(1)
 {
   printf("\nenter your choice\n1.create BST\n2.inorde\n3.preorder\n4.postorder\n5.search\n6.exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:printf("enter the no. of node in BST\n");
           scanf("%d",&n);
           for(i=0;i<n;i++)
           {
             printf("enter the element to be iserted\n");
             scanf("%d",&key);
             root=insert(root,key);
           }
           break;
     case 2:inorder(root);
            break;
     case 3:preorder(root);
            break;
     case 4:postorder(root);
            break;
     case 5:printf("enter the element to be searched\n");
            scanf("%d",&key);
            pos=search(root,key);
            if(pos==-1)
             printf("\nkey not found\n");
            else
             printf("key found\n");
            break;
     case 6:exit(0);
   }
 }
 return 0;
}
