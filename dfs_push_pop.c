#include <stdio.h>
#include <stdlib.h>

int n,pui=0,poi=0;
int push[100],pop[100];

void printC(int count[])
{
	for(int i=0;i<n;i++)
		printf("%d\t",count[i]);
}

void dfs(int count[],int a[][n],int v)
{
	push[pui]=v;
	pui++;
	count[v]=1;
	for(int i=0;i<n;i++)
	{
		printf("\n%d %d\n",v,i);
		if(a[v][i]==1 && count[i]==0)
			dfs(count,a,i);
	}
	pop[poi]=v;
	poi++;
	printf("\nLeaving %d %d %d\n",pui,poi,v);
	printC(count);
}


int main()
{
	int x=0;
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	int arr[n][n],count[n];
	for(int i=0;i<n;i++)
	{
		count[i]=0;
		for(int j=0;j<n;j++)
			arr[i][j]=0;
	}
	for(int i=0;i<n;i++)
	{
		printf("Enter vertices adjacent to %d [-1 to exit]\n",i);
		x=0;
		while(x!=-1)
		{
			scanf("%d",&x);
			if(x!=(i) && x>0 && x<=n)
				arr[i][x]=arr[x][i]=1;
		}
	}

	//printC(count);
	for(int i=0;i<n;i++)
		if(count[i]==0)
			dfs(count,arr,i);

	printf("\nPrinting matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",arr[i][j] );
		printf("\n");
	}

	printf("Pushing order: ");
	for(int i=0;i<n;i++)
		printf("%d\t",push[i]);
	printf("\nPopping order: ");
	for(int i=0;i<n;i++)
		printf("%d\t",pop[i]);
	printf("\n");

}