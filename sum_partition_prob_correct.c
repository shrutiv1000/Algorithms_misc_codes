#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int opcount=0;
int isKthBitSet(int n, int k) 
{ 
    if ((n >> (k - 1)) & 1) 
        return 1; 
    else
        return 0; 
} 
int partition(int arr[],int n,int sum)
{
	int t = pow(2,n) - 1;
	int a[t][n];
	int k=0;
	for(int i=1;i<=t;i++)
	{k=0;
		for(int j=1;j<=n;j++)
		{
			if(isKthBitSet(i,j))
			{
				a[i-1][k++]=arr[n-j];
			}
			else
				a[i-1][k++]=0;
		}
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",a[i][j] );
		printf("\n");
	}
	int summ[t];
	for(int i=0;i<t;i++){
		summ[i]=0;
		for(int j=0;j<n;j++)
			summ[i]=summ[i]+a[i][j];
			if(summ[i]==sum/2)
			{
				printf("\nSet 1: ");
				for(int k=0;k<n;k++)
				{
					if(a[i][k]!=0)
						printf("%d\t",a[i][k]);
				}
				printf("\nSet 2: ");
				for(int k=0;k<n;k++)
				{
					if(arr[k]!=a[i][n-k-1])
						printf("%d\t",arr[k]);
				}
				return 1;
		}	}
	return 0;
}
int main()
{
	int n,sum=0;
	printf("Enter the size of array:  ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum=sum+arr[i];
	}
	if(sum%2==1)
		printf("\nCannot be partitioned.");
	else if(partition(arr,n,sum))
		printf("\nCan be Partitioned.");
		else
			printf("\nCannot be Partiotioned.");
	printf("\nOperation Count: %d",opcount);	

}