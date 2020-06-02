#include<stdio.h>
#include<stdlib.h>
int opcount=0;
void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void heapify(int n,int heap[])
{
	int i,j,k,t;
	i=n>>1;
	while(i>0){
		j=2*i;
		k=(2*i) + 1;
		if(k<=n)
		{
			if(heap[j]>heap[k])
				t=j;
			else
				t=k;
		}
		else
			t=j;
		opcount++;
		if(heap[i]>=heap[t])
			i--;
		else{
			swap(heap,i,t);
			if(2*t<=n){
				if(heap[t]<heap[2*t])
					i=t;
				else if(((2*t)+1)<=n && heap[t]<heap[(2*t)+1])
					i=t;
				else 
					i--;
			}
			else
				i--;
		}
	}
}
void heapsort(int heap[],int n)
{
	int i=n;
	while(i>1)
	{
		heapify(i,heap);
		swap(heap,1,i);
		i--;
	}
}
int main()
{
	int n;
	printf("Enter the size of heap: ");
	scanf("%d",&n);
	int heap[n+1];
	printf("Enter the elements of heap: ");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&heap[i]);
	}
	heapsort(heap,n);
	printf("The sorted array is:  ");
	for(int i=1;i<=n;i++)
	{
		printf("%d\t",heap[i]);
	}
	printf("\nOperation Count: %d",opcount);
}