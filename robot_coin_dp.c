#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int m,n;
	printf("Enter row and column size: ");
	scanf("%d %d",&m,&n);
	printf("Enter coins: ");
	int c[m][n],k[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&c[i][j]);
	}
	k[0][0]=c[0][0];
	for(int j=1;j<n;j++)
		k[0][j]=k[0][j-1]+c[0][j];
	for(int i=1;i<m;i++)
	{
		k[i][0]=k[i-1][0]+c[i][0];
		for(int j=1;j<n;j++)
			k[i][j]=max(k[i-1][j],k[i][j-1])+c[i][j];
	}
	printf("The maximum is: %d",k[m-1][n-1]);
}