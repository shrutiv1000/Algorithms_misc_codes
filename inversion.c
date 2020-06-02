#include <stdio.h> 
#include <stdlib.h> 
int c=0;
void count_(int arr[],int l1, int r1, int l2, int r2)
{
	for(int i=l1;i<=r1;i++)
	{
		for(int j=l2;j<=r2;j++)
		{
			if(arr[i]>arr[j]){
				printf("(%d,%d)\t",arr[i],arr[j]);
				c++;
			}
		}
	}
}
void count_inv(int arr[],int l,int r)
{
	int mid;
	if(l<r)
	{
		mid=(l+r)/2;
		count_inv(arr,l,mid);
		count_inv(arr,mid+1,r);
		count_(arr,l,mid,mid+1,r);
	}
}
int main()
{
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter array elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\n");
	count_inv(arr,0,n-1);
	printf("\nTotal Inversions: %d",c);
}