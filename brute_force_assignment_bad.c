#include<stdio.h>
int n;
int r1;
int f;
int combinations[1000][10];
int opcount=0;
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
void main()
{
	printf("Enter n:");
	scanf("%d",&n);
	int square[n][n];
	for(int i=0;i<n;i++)
	{
		printf("Enter costs for person %d: ",(i+1));
		for(int j=0;j<n;j++)
		{
			scanf("%d",&square[i][j]);
		}
	}
	int numbers[n];
	for(int i=0;i<n;i++)
	{
		numbers[i]=i;
	}
	r1=0;
	permute(numbers,0,n-1);
	int temp[n];
	int jobs[n];
	int ans[fact(n)][2];
	int minn=0;
	for(int i=0;i<fact(n);i++)
	{
		opcount++;
		for(int j=0;j<n;j++)
		{
			temp[j]=combinations[i][j];
		}
		for(int k=0;k<n;k++)
		{
			jobs[k]=square[k][temp[k]];
		}
		int sum=0;
		for(int l=0;l<n;l++)
		{
			sum=sum+square[l][combinations[i][l]];
		}
		ans[i][0]=sum;
		ans[i][1]=i;
		if(ans[i][0]<ans[minn][0])
			minn=i;
	}
	/*for(int i=0;i<fact(n);i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d\t",ans[i][j]);
		}
		printf("\n");
	}*/
	/*int min=ans[0][0];
	int thatj=0;
	for(int i=0;i<fact(n);i++)
	{
		if(ans[i][0]<min)
		{
			min=ans[i][0];
			thatj=i;
		}
	}*/
	printf("Minimum cost is %d\n", ans[minn][0]);
	for(int i=0;i<n;i++)
	{
		printf("Person %d will be assigned %d job\n",(i+1),combinations[minn][i]+1);
	}
	//printf("\n %d %d",thatj,minn);
	printf("\ncount is %d\n",opcount);
}