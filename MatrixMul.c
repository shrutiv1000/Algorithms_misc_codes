#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m,n,p,q,i,j,k;
	printf("Dimensions of 1st matrix: ");
	scanf("%d",&m);
	scanf("%d",&n);
	printf("Dimensions of 2nd matrix: ");
	scanf("%d",&p);
	scanf("%d",&q);
	if(n!=p)
	{
		printf("Not possible\n");
		exit(0);
	}
	int a[m][n],b[p][q],c[m][q];
	printf("Elements of 1st matrix:\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);	
	printf("Elements of 2nd matrix:\n");
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&b[i][j]);

	for(i=0;i<m;i++)
		for(j=0;j<q;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	printf("Printing\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}

}