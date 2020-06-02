#include<stdio.h>
#include<stdlib.h>
int opcount=0;
int n;
void DFS(int i,int visited[],int a[][n])
{
  int j;
  printf("%d\t",i);
  visited[i]=1;
  for(j=0;j<n;j++){
    opcount++;
    if(!visited[j]&&a[i][j]==1)
       DFS(j,visited,a);
    else if(visited[j]==1 && a[i][j]==1)
    {
      printf("\nGraph Contains Cycle. Back to: %d",j);
      exit(0);
    }

  }
}   
void main()
{
  int i,j;
  printf("Enter number of vertices:");
	scanf("%d",&n);
  int a[n][n],visited[n];
	printf("\nEnter adjecency matrix of the graph:");
	for(i=0;i<n;i++)
       for(j=0;j<n;j++){
        //printf("\n %d and %d  ",i,j);
			  scanf("%d",&a[i][j]);
      }
   for(i=0;i<n;i++)
        visited[i]=0;
    printf("Enter the node to start: ");
    int p;
    scanf("%d",&p);  
    printf("DFS Traversal:\n");
    DFS(p,visited,a);
    for(j=0;j<n;j++)
    {
      if(visited[j]==0)
        DFS(j,visited,a);
    }
    printf("\nGraph does not contain any cycle.");
    printf("\nOperation Count=%d",opcount);
}
 
