#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int opcount=0;
int partition(int arr[],int n,int sum)
{
	int sump=0;
	//int t=(pow(2,n))-1;
	for(int i=0;i<n;i++)
	{
		//printf("\ni=%d",i);
		for(int j=i+1;j<n;j++)
		{
			//sump=0;
			sump=arr[i];
			//printf("\ni=%d  j=%d  sump=%d",i,j,sump);
			opcount++;
			if(sump==(sum-sump)){
				printf("Set 1: %d\nSet 2: ",arr[i]);
				for(int l=0;l<n;l++)
				{
					if(l!=i)
						printf("%d\t",arr[l]);
				}
				return 1;
			}
			for(int k=j;k<n;k++)
			{
				opcount++;
				sump=sump+arr[k];
				//printf("\ni=%d  j=%d  k=%d  sump=%d",i,j,k,sump);
				if(sump==(sum-sump)){
					printf("Set 1: %d\t",arr[i]);
					for(int l=j;l<=k;l++)
						printf("%d\t",arr[l]);
					printf("\nSet 2: ");
					for(int l=k+1;l<n;l++)
					{
						printf("%d\t",arr[l]);
					}
					for(int l=i+1;l<j;l++)
					{
						printf("%d\t",arr[l]);
					}
					for(int l=0;l<i;l++)
					{
						printf("%d\t",arr[l]);
					}
				return 1;}
			}
		}
	}
	return 0;
}
int main()
{
	int n,sum=0;
	printf("Enter the size of array:  ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum=sum+arr[i];
	}
	if(sum%2==1)
		printf("\nCannot be partitioned.");
	else if(partition(arr,n,sum))
		printf("\nCan be Partitioned.");
		else
			printf("\nCannot be Partiotioned.");
	printf("\nOperation Count: %d",opcount);	

}