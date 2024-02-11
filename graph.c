//indegree,outdgree,totaldgree program
#include<stdio.h>
void indgree(int a[10][10],int n)
{
  int i,j,in;
  for(i=1;i<=n;i++)
  {
    in=0;
    for(j=1;j<=n;j++)
    {
      in=in+a[j][i];
    }
    printf("\n indgree ofv%d=%d",i,in);
  }
}
void outdgree(int a[10][10],int n)
{
  int i,j,out;
  for(i=1;i<=n;i++)
  {
    out=0;
    for(j=1;j<=n;j++)
    {
      out=out+a[i][j];
    }
    printf("\n outdgree ofv%d=%d",i,out);
  }
}
void totaldgree(int a[10][10],int n)
{
  int i,j,total;
  for(i=1;i<=n;i++)
  {
    total=0;
    for(j=1;j<=n;j++)
    {
      total=total+a[j][i]+a[i][j];
    }
    printf("\n indgree ofv%d=%d",i,total);
  }
}
int main()
{
  int a[10][10],i,j,n;
  printf("Enter limit");
  scanf("%d",&n);
  printf("Enter graph in the matrix format");
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
        scanf("%d",&a[i][j]);
     }
  } 
  indgree(a,n);
  outdgree(a,n);
  totaldgree(a,n);
}
