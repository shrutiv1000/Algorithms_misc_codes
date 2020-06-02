#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,i,j,sum,sumcom;
	printf("Enter no. of elements : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=1;i<pow(2,n);i++)
	{
		sum=0;
		sumcom=0;
		for(j=0;j<n;j++)
		{
			if(i & (1<<j))
				sum+=a[j];
			else
				sumcom+=a[j];
		}
		if(sum==sumcom)
		{
			printf("Set 1:\t");
			for(j=0;j<n;j++)
				if(i & (1<<j))
					printf("%d\t",a[j] );
			printf("\nSet 2:\t");
			for(j=0;j<n;j++)
				if(!(i & (1<<j)))
					printf("%d\t",a[j] );
			exit(0);
		}
	}
	printf("Partition not possible\n");
}