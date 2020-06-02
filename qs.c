#include <stdio.h> 
#include <stdlib.h> 
int opcount=0;
int partition(int a[],int l,int r)
{
	int v,i,j,temp;
	v=a[l];
	i=l;
	j=r+1;
	while(i<j)
	{
		do{
			opcount++;
			i++;
		}while(a[i]<v&&i<=r);
		do{
			opcount++;
			j--;
		}while(v<a[j]);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	
	a[l]=a[j];
	a[j]=v;
	
	return(j);
}     
void quick_sort(int a[],int l,int u)
{
	int j;
	if(l<u)
	{
		
		j=partition(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}
}
int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Unsorted Array:\t");
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	quick_sort(arr,0,n-1);
	printf("\nSorted Array:\t");
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\nOperation Count: %d\n",opcount);
}
 