#include<stdio.h>
#include <stdlib.h>

void insert(int a[],int x,int p,int n)
{
	for(int i=p;i<p+n;i++)
		if(a[i%n]==-1)
		{
			a[i%n]=x;
			return;
		}
}

int main()
{
	int m,n,x;
	printf("m: ");
	scanf("%d",&m);
	printf("n: ");
	scanf("%d",&n);
	if(n>m)
	{
		printf("Not possible\n");
		exit(0);
	}
	int table[m];
	for(int i=0;i<m;i++)
		table[i]=-1;
	printf("Enter keys\n");
	for(int i=0;i<n;i++)
	{
		printf("x: ");
		scanf("%d",&x);
		insert(table,x,x%m,m);
	}
	printf("Printing:\n");
	for(int i=0;i<m;i++)
	{
		if(table[i]!=-1)
			printf("%d: %d\n",i,table[i] );
		else
			printf("%d: \n",i );
	}

}