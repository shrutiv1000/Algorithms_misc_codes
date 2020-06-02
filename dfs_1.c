#include<stdio.h>
#include<stdlib.h>
int opcount=0;
int n;
int k=0;
void dfs(int a[][n], int u,int s[],int t[][2])
{
	
	s[u]=1;
	int i,flag=1;
	for(i=0;i<n;i++)
	{
		if(a[u][i]==1 && s[i]==0)
		{
			opcount++;
			t[k][0]=u;
			t[k][1]=i;
			k++;
			break;
		}
	}
	for(int j=0;j<n;j++)
	{
		if(s[j]==0)
			flag=0;
	}
	if(flag==0){
	dfs(a,i,s,t);}
	else
		return;
}
int main()
{
	int u;
	printf("Enter n: ");
	scanf("%d",&n);
	int a[n][n];
	printf("Enter adjacency matrix: ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("\nEnter adjacency for vertex %d and vertex %d: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter source vertex: ");
	scanf("%d",&u);
	int s[n];
	for(int i=0;i<n;i++)
		s[i]=0;
	int t[25][2];
	dfs(a,u,s,t);
	for(int i=0;i<k;i++)
		printf("%d %d\n",t[i][0],t[i][1]);
	printf("\nOperation Count: %d",opcount);
}