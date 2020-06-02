#include <stdio.h> 
#include <stdlib.h> 
int opcount=0,c=0;
void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];	
	int i,j,k;
	i=i1;	
	j=i2;	
	k=0;
	while(i<=j1 && j<=j2)
	{
		opcount++; 
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else{c++;
			temp[k++]=a[j++];
		}
	}
	while(i<=j1){
		opcount++;	
		temp[k++]=a[i++];}
	while(j<=j2){opcount++;
	c++;	
		temp[k++]=a[j++];}
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}
void mergesort(int a[],int i,int j)
{
	int mid;
		
	if(i<j)
	{
		//opcount++;
		mid=(i+j)/2;
		mergesort(a,i,mid);	
		mergesort(a,mid+1,j);	
		merge(a,i,mid,mid+1,j);	
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
	mergesort(arr,0,n-1);
	
	printf("\n Count: %d\n",c);
}