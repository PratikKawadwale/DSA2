//heapify function
#include<stdio.h>
void accept(int a[],int n)
{
   int i;
   printf("Enter number :");
   for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
}
void display(int a[],int n)
{
  int i;
  printf("Enter number");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}
int heapify(int a[],int top,int last)
{
  int key=top;
  int j=(2*top+1);
  if(j<=last && a[j]<a[j+1])
  {
     j=j+1;
  }
  if(j<=last && key<a[j])
  {
    int temp=a[top];
    a[top]=a[j];
    a[j]=temp;
    heapify(a,j,last);
  }
}
void buildheap(int a[],int n)
{
  for(int i=(n/2)-1;i>=0;i--)
  {
    heapify(a,i,n-1);
  }
}
void heapsort(int a[],int n)
{
  int last=0;
  int top=0;
  buildheap(a,n);
  printf("\nINITIOAL HEAP");
  display(a,n);
  for(last=n-1;last>1;last--)
  {
    int temp=a[top];
    a[top]=a[last];
    a[last]=temp;
    printf("\nITERATION:%d",n-last);
    display(a,n);
    heapify(a,top,last-1);
  }
}
int main()
{
   int n,a[100];
   printf("Enter limit");
   scanf("%d",&n);
   accept(a,n);
   display(a,n);
   heapsort(a,n);
}
