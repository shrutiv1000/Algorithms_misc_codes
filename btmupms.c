#include <stdio.h>
int n;
int min(int x,int y)
{
	if(x<y)
		return x;
	else
		return y;
}
void merge(int arr[],int left,int middle,int right)
{
	int l1=left,l2=middle+1,r1=middle,r2=right;
	int temp[n],k=0,p=0;
	while(l1<=r1 && l2<=r2)
	{
		if(arr[l1]<arr[l2])
			temp[k++]=arr[l1++];
		else
			temp[k++]=arr[l2++];
	}
	while(l1<=r1)
		temp[k++]=arr[l1++];
	while(l2<=r2)
		temp[k++]=arr[l2++];
	//printf("\n l=%d m=%d r=%d",left,middle, right);
	for(int i=left;i<=right;i++){
		if(p<k)
		arr[i]=temp[p++];
		//printf(" temp: %d arr: %d",temp[k],arr[i]);
	}
}
void merge_sort(int arr[],int l,int r)
{
	for(int gap=1;gap<=n-1;gap=gap*2)
	{
		for(int i=0;i<n;i=i+2*gap)
		{
			int mid = min(i + gap - 1, n-1);
            int right_end = min(i + 2*gap -1 , n-1); 
				merge(arr,i,mid,right_end);
		}
	}
}
int main()
{
	printf("Enter number of elements: ");`
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	merge_sort(arr,0,n-1);
	printf("Sorted Array: ");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
}