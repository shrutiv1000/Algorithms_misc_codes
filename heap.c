#include<stdio.h>
#include<stdlib.h>
int opcount=0;
int main()
{
	int n,j,temp;
	printf("Enter the size of heap: ");
	scanf("%d",&n);
	int heap[n+1];
	printf("Enter the elements of heap: ");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&heap[i]);
		j=i>>1;
		if(j>0)
		{
			opcount++;
			if(heap[i]>heap[j])
			{
				temp=heap[i];
				heap[i]=heap[j];
				heap[j]=temp;
			}
		}
	}
	printf("The heap is:  ");
	for(int i=1;i<=n;i++)
	{
		printf("%d\t",heap[i]);
	}
	printf("\nOperation Count: %d",opcount);
}