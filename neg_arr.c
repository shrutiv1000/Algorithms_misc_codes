#include <stdio.h>
int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int i=0,j=n-1,temp,exit=0;
	while(i<j)
	{
		while(arr[i]<0 && i<n-1)
		{
			i=i+1;
		}
		while(arr[j]>0 && j>=0)
		{
			j=j-1;
		}
		if(arr[i]>0 && arr[j]<0 && i<j){
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;}
		i++;
		j--;
		for(int i=0;i<n;i++)
			printf(" %d ",arr[i]);
	}
	printf("\nRequired Array: ");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
}