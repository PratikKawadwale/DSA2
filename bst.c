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
void preorder(Node *root)
{
   Node *temp=root;
     if(temp!=NULL)
     {
         printf("%d\t",temp->data);
         preorder(temp->left);
         preorder(temp->right);
     }
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
void postorder(Node *root)
{
   Node *temp=root;
     if(temp!=NULL)
     {
         postorder(temp->left);
         postorder(temp->right);
         printf("%d\t",temp->data);
     }
}
int search(Node *root)
{
   Node *temp=root;
   int num;
   printf("Enter number");
   scanf("%d",&num);
   while(temp!=NULL)
   {
     if(num==temp->data)
       return 1;
     else
       if(num<temp->data)
        temp=temp->left;
       else
        temp=temp->right;
   }return 0;
}
int leafnode(Node *root)
{
  Node *temp=root;
  static int c=0;
  if(temp!=NULL)
  {
     if(temp->left==NULL && temp->right==NULL)
             c++;
        leafnode(temp->left);
        leafnode(temp->right);
  }return c;
}
int caunt(Node *root)
{
   Node *temp=root;
   static int c=0;
   if(temp!=NULL)
   {
     c++;
     caunt(temp->left);
     caunt(temp->right);
   }return c;
}
Node *copy(Node *root)
{
  Node *newnode,*temp=root;
    if(temp!=NULL)
    {
       newnode=memory;
       newnode->data=temp->data;
       newnode->left=copy(temp->left);
       newnode->right=copy(temp->right);
       return newnode;
    }return NULL;
}
Node *mirror(Node *root)
{
   Node *temp=root,*temp1;
   if(temp!=NULL)
   {
     temp->left!=NULL;
     mirror(temp->left);
     temp->right!=NULL;
     mirror(temp->right);
     
     temp1=temp->left;
     temp->left=temp->right;
     temp->right=temp1;
   }return root;
}
int main()
{
  int ch,num,c,ans;
  Node *root=NULL,*newnode,*root1,*root2;
  do{
    printf("\n1-create\n2-preorder\n3-inorder\n4-postorder\n5-search\n6-leafnode\n7-caunt\n8-copy\n9-mirror");
    printf("\nEnter choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:root=create(root);
            break;
      case 2:preorder(root);
             break;
      case 3:inorder(root);
             break;
      case 4:postorder(root);
             break;
      case 5:num=search(root);
              if(num==1)
                printf("number is faund");
              else
               printf("number is not faund");
               break;
      case 6:c=leafnode(root);
             printf("leaf node:%d",c);
             break;
      case 7:c=caunt(root);
             printf("caunt node:%d",c);
             break;       
      case 8:newnode=copy(root);
             inorder(root);
             break;
      case 9:root=mirror(root);
             break;
   }
   }while(ch<10);
   
}
