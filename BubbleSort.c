#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i,j;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	printf("List: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i] );
}