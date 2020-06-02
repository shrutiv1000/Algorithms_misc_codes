#include <stdio.h>
int n,r1=0,comb[1000][100];
int fact(int n)
{
	if(n==1 || n==0)
		return 1;
	else
		return (n*fact(n-1));
}
int permute(int num[],int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<n;i++)
		{
			comb[r1][i]=num[i];
		}
		r1++;
	}
	for(int i=l;i<=r;i++)
	{
		int temp=num[l];
		num[l]=num[i];
		num[i]=temp;
		permute(num,l+1,r);
		temp=num[l];
		num[l]=num[i];
		num[i]=temp;
	}
}
int main()
{
	printf("Enter number of people and jobs: ");
	scanf("%d",&n);
	int matrix[n][n];
	printf("Enter the matrix: ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);
	}
	int num[n];
	for(int i=0;i<n;i++)
	{
		num[i]=i;
	}
	permute(num,0,n-1);
	int cost[fact(n)];
	for(int i=0;i<fact(n);i++)
	{
		cost[i]=0;
		for(int j=0;j<n;j++)
		{
			cost[i]=cost[i]+matrix[j][comb[i][j]];
		}
	}
	int min=0;
	printf("\nAll Costs: \n");
	for(int i=0;i<fact(n);i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",comb[i][j]);
		}
		printf(" %d\n",cost[i]);
	}
	for(int i=1;i<fact(n);i++)
	{
		if(cost[i]<cost[min])
			min=i;
	}
	printf("\nMinimum Cost: %d\nJob Assignment: \n",cost[min]);
	for(int i=0;i<n;i++)
	{
		printf("%d - %d\n",i,comb[min][i]);
	}
}