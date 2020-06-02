#include<stdio.h>
#include<stdlib.h>
int n,k=0;
void top_sort(int arr[][n],int in[],int visited[],int order[])
{
	int f=0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0 && in[i]==0)
		{
			f=1;
			visited[i]=1;
			order[k++]=i;
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]==1)
					in[j]-=1;
			}
		}
	}
	if(f==0)
	{
		printf("\nNot a DAG.");
		exit(0);
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
			top_sort(arr,in,visited,order);
	}
	return;
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
	int in[n],visited[n],order[n];
	for(int i=0;i<n;i++)
	{
		in[i]=0;
		visited[i]=0;
		for(int j=0;j<n;j++)
		{
			in[i]+=arr[j][i];
		}
	}
	top_sort(arr,in,visited,order);
	printf("\nTopological Sort Order: ");
	for(int i=0;i<n;i++)
		printf("%d ",order[i]);
}