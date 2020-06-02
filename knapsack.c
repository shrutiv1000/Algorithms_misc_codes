#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
int powerset(int arr[][n])
{
	int t=pow(2,n);
	int k=0;
	for(int i=0;i<t;i++)
	{
		k=0;
		for(int j=0;j<n;j++)
		{
			if((i >> j) & 1)
			{
				arr[i][k++]=j;
			}
			else
				arr[i][k++]=-1;
		}
	}
}
int main()
{
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n][2];
	printf("Enter weight and value of products: ");
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i][0],&a[i][1]);
	int t=pow(2,n);
	int arr[t][n],value;
	powerset(arr);
	printf("Enter the weight of Knapsack: ");
	scanf("%d",&value);
	int cost[t],weight[t];
	for(int i=0;i<t;i++)
	{
		cost[i]=0;
		weight[i]=0;
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]!=-1)
			{
				weight[i]=weight[i]+a[arr[i][j]][0];
				cost[i]=cost[i]+a[arr[i][j]][1];
			}
		}
	}
	int max=0;
	for(int i=0;i<t;i++)
	{
		if(weight[i]<=value)
		{
			if(cost[i]>=cost[max])
				max=i;
		}
	}
	printf("Max Cost: %d\nItems: ",cost[max]);
	for(int i=0;i<n;i++)
	{
		if(arr[max][i]!=-1)
			printf("%d ",arr[max][i]);
	}
}