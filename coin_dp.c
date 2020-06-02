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
	int n;
	printf("Enter number of Coins: ");
	scanf("%d",&n);
	printf("Enter value of coins: ");
	int c[n+1],f[n+1];
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	f[0]=0;
	f[1]=c[1];
	for(int i=2;i<=n;i++)
	{
		f[i]=max((c[i]+f[i-2]),f[i-1]);
	}
	printf("\nThe max value: %d",f[n]);
}