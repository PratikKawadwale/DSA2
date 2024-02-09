//binary search compare program
//binary search tree program
#include<stdio.h>
#include<stdlib.h>
#define memory (struct node*)malloc(sizeof(struct node))
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *create(Node *root)
{
  Node *newnode,*temp,*parent;
  int i,n,num;
  printf("Enter limit");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    newnode=memory;
    printf("Enter number");
    scanf("%d",&newnode->data);
    num=newnode->data;
    newnode->left=newnode->right=NULL;
    if(root==NULL)
    {
    root=newnode;
    continue;
    }
    temp=root;
    while(temp!=NULL)
    {    
        parent=temp;
         if(num<temp->data)
          {
            temp=temp->left;
          }
         else
         {
           temp=temp->right;
         }
    }
     if(num<parent->data)
       {
        parent->left=newnode;
      }
    else
    {
        parent->right=newnode;
    }
  }return root;
}  
void inorder(Node *root)
{
   Node *temp=root;
     if(temp!=NULL)
     {
         inorder(temp->left);
         printf("%d\t",temp->data);
         inorder(temp->right);
     }
}
int compare(Node* root1,Node *root2)
{
   if(root1==NULL && root2==NULL)
    return 1;
   else if(root1!=NULL && root2!=NULL)
   {
      if(root1->data==root2->data)
      {
         if(compare(root1->left,root2->left)&&compare(root1->right,root2->right))
         {
           return 1;
         }
         else
          return 0;
      }
   }
}
int main()
{
  Node *root1=NULL,*root2=NULL;
  int ans;
  root1=create(root1);
  printf("\n");
  root2=create(root2);
  printf("\n");
  printf("compair root");
  ans=compare(root1,root2);
            if(ans==1)
              printf("equal");
            else
            printf("Not equal");
}
