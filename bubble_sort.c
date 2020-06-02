#include<stdio.h>
#include<stdlib.h>
int opcount=0;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++) {
       for (j = 0; j < n-i-1; j++) {
       	opcount++;
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
   }}
} 
int main()
{
	int n;
	printf("Enter the size of array");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the %d elements of array: ",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Non-Sorted Array:  ");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	bubbleSort(arr,n);
	printf("\nSorted Array:     ");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nOperation Count: %d\n",opcount);
}