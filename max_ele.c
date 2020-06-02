#include <stdio.h>
int n,maxval,maxi,minval,mini;
void merge(int arr[],int l1,int r1,int l2,int r2)
{
	int i=l1,j=l2;
	while(i<=r1 && j<=r2)
	{
		if(arr[i]>maxval){
			maxval=arr[i];
			maxi=i;
		}
		if(arr[i]<minval){
			minval=arr[i];
			mini=i;
		}
		i++;
		if(arr[j]>maxval){
			maxval=arr[j];
			maxi=j;
		}
		if(arr[j]<minval){
			minval=arr[j];
			mini=j;
		}
		j++;
	}
	while(i<=r1)
	{
		if(arr[i]>maxval){
			maxval=arr[i];
			maxi=i;
		}
		if(arr[i]<minval){
			minval=arr[i];
			mini=i;
		}
		i++;
	}
	while(j<=r2)
	{
		if(arr[j]>maxval){
			maxval=arr[j];
			maxi=j;
		}if(arr[j]<minval){
			minval=arr[j];
			mini=j;
		}
		j++;
	}
}
void merge_sort(int arr[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,r);
		merge(arr,l,mid,mid+1,r);
	}
}
int main()
{
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	maxval=arr[0],maxi=0,minval=arr[0],mini=0;
	merge_sort(arr,0,n-1);
	printf("\nLargest element: %d Position: %d",maxval,maxi+1);
	printf("\nSmallest element: %d Position: %d",minval,mini+1);

}