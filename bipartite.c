#include<stdio.h>
#include<stdlib.h>
int opcount=0;
int n;
int DFS(int i,int visited[],int a[][n],int color[])
{
  int j;
  printf("\t%d",i);
  visited[i]=1;
  for(j=0;j<n;j++){
    opcount++;
    if(!visited[j]&&a[i][j]==1){
      color[j]=!color[i];
       DFS(j,visited,a,color);
  }else if(visited[j]&&a[i][j]==1)
  {
    if(color[i]==color[j]){
      printf("\nNot a bipartite graph.");
      exit(0);
    }
  }
}
return 1;
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
			  scanf("%d",&a[i][j]);
      }
   for(i=0;i<n;i++)
        visited[i]=0;
    printf("Enter the node to start: ");
    int p,color[n],q;
    scanf("%d",&p);
    color[p]=1;
    printf("DFS traversal order:"); 
    q=DFS(p,visited,a,color);
     for(j=0;j<n;j++)
    {
      if(visited[j]==0){
        printf("Not a connected Graph.");
        exit(0);
      }
    }
    if(q!=-1)
    {
      printf("\nBipartite Graph\nPartitions: \n");
      for(i=0;i<n;i++)
      {
        if(color[i]==1)
          printf("%d\t",i);
      }printf("\n");
      for(i=0;i<n;i++)
      {
        if(color[i]!=1)
          printf("%d\t",i);
      }
    }
    printf("\nOperation Count=%d",opcount);
}
 
