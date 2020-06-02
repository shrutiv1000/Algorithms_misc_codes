#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("Enter n ");
	scanf("%d",&n);
	int c[n][n];
	printf("Enter elements: ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&c[i][j]);
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				c[i][j]=c[i][j]||(c[i][k]&&c[k][j]);
			}
		}
	}
	printf("\nThe transitive closure: \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
}