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
				arr[i][k++]=j+1;
			}
			else
				arr[i][k++]=0;
		}
	}
}
int main()
{
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int t=pow(2,n);
	int arr[t][n];
	powerset(arr);
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
}