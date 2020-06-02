#include<stdio.h>
#include<stdlib.h>

int TopDown(int a[],int n)
{
	int i;
	for(i=1;i<n;i++)
		if(a[i]==a[n])
			return n-1;
	i=n;
	while(i/2>0)
	{
		if(a[i]>a[i/2])
		{
			int temp=a[i];
			a[i]=a[i/2];
			a[i/2]=temp;
			i=i/2;
		}
		else
			break;
	}
	return n;

}

int main(){
	int n,i,j;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	int a[n+1];
	a[0]=0;
	printf("Enter elements\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		i=TopDown(a,i);
	}

	printf("List: ");
	for(i=1;i<=n;i++)
		printf("%d\t",a[i] );
}