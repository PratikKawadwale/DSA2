#include<stdio.h>
int g[10][10],visited[10]={0},n;
void dfs(int i)
{
  int j;
  printf("\n%d",i);
  visited[i]=1;
  for(j=1;j<=n;j++)
  {
     if(g[i][j]==1 && visited[j]==0)
     {
       dfs(j);
     }
  }
}
int main()
{
  int i,j;
  printf("Enter number of vertices");
  scanf("%d",&n);
  printf("\nEnter adjacency matrix of the graph");
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    scanf("%d",&g[i][j]);
    
    dfs(1);
}
