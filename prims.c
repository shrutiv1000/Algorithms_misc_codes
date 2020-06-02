#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int cost=0,n;
int notin(int visited[],int v)
{
	for(int i=0;i<n;i++)
	{
		if(visited[i]==v)
			return 0;
	}return 1;
}
void prims(int adj[][n],int visited[])
{
	if(visited[n-1]!=-1)
		return;
	int i=0,min=INT_MAX,mini,minj;
	while(visited[i]!=-1)
	{
		for(int j=0;j<n;j++)
		{
			if(adj[visited[i]][j]!=0 && adj[visited[i]][j]<min && notin(visited,j))
			{
				min=adj[visited[i]][j];
				mini=visited[i];
				minj=j;
			}
		}i++;
	}
	cost+=min;
	visited[i]=minj;
	prims(adj,visited);
}
int main()
{
	printf("Enter number of edges: ");
	scanf("%d",&n);
	int adj[n][n];
	printf("Enter adjacency matrix: ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&adj[i][j]);
	}
	int visited[n];
	for(int i=0;i<n;i++)
		visited[i]=-1;
	printf("Enter starting vertex: ");
	scanf("%d",&visited[0]);
	prims(adj,visited);
	printf("The cost is: %d and the route is: ");
	for(int i=0;i<n;i++)
		printf("%d ",visited[i]);
}