#include <stdio.h>
#include <stdlib.h>

void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

int Partition(int a[],int l,int r)
{
	int p=a[l];
	int i=l,j=r+1;
	do
	{
		do{i+=1;}while(a[i]<p);
		do{j-=1;}while(a[j]>p);
		swap(a,i,j);
	}while(i<j);
	swap(a,i,j);
	swap(a,l,j);
	return j;
}

void QuickSort(int a[],int l,int r)
{
	if(l<r)
	{
		int s=Partition(a,l,r);
		QuickSort(a,l,s-1);
		QuickSort(a,s+1,r);
	}
}

int main()
{
	int n;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	QuickSort(a,0,n-1);
	printf("Printing:   ");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
}