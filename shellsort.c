#include<stdio.h>
int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for (int gap = n/2; gap > 0; gap /= 2){
    for (int i = gap; i < n; i += 1) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
	printf("Sorted Array: ");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
}