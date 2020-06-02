#include<stdio.h>
#include<stdlib.h>
int n,k=0;
void top_sort(int arr[][n],int v,int visited[],int order[])
{
	visited[v]=1;
	for(int i=0;i<n;i++)
	{
		if(arr[v][i]!=0 && visited[i]==0)
			top_sort(arr,i,visited,order);
		else if(arr[v][i]!=0 && visited[i]==1)
		{
			printf("\nNot a DAG.");
			exit(0);
		}
	}
	order[k++]=v;
}
int main()
{
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	int arr[n][n];
	printf("Enter the adjacency matrix: ");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	int visited[n],order[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	top_sort(arr,0,visited,order);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
			top_sort(arr,i,visited,order);
	}
	printf("%d",k);
	printf("\nTopological Sort Order: ");
	for(int i=n-1;i>=0;i--)
		printf("%d ",order[i]);
}