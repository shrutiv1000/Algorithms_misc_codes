#include<stdio.h>
int n,r1,f;
int combinations[1000][10];
int fact(int n)
{
	if(n==1)
		return 1;
	else
		return fact(n-1)*n;
}
void permute(int numbers[], int l, int r)
{
	if(l==r)
	{
		for(int i=0;i<n;i++)
		{
			combinations[r1][i]=numbers[i];
		}
		r1++;
		return;
	}
	for(int i=l;i<=r;i++)
	{
		int temp=numbers[l];
		numbers[l]=numbers[i];
		numbers[i]=temp;
		permute(numbers, l+1, r);
		temp=numbers[l];
		numbers[l]=numbers[i];
		numbers[i]=temp;
	}
}
int main()
{
	printf("Enter n: ");
	scanf("%d",&n);
	int numbers[n];
	for(int i=0;i<n;i++)
	{
		numbers[i]=i;
	}
	permute(numbers,0,n-1);
	printf("Permutations: \n");
	for(int i=0;i<fact(n);i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",combinations[i][j]);
		printf("\n");
	}
}