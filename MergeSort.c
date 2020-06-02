#include <stdio.h>

void Merge(int b[],int c[],int a[],int p,int q)
{
	int i=0,j=0,k=0;
	while(i<p && j<q)
	{
		if(b[i]<=c[j])
		{
			a[k]=b[i];
			i++;
		}
		else
		{
			a[k]=c[j];
			j++;
		}
		k++;
	}
	if(i==p)
	{
		while(j<q)
		{
			a[k]=c[j];
			j++;k++;
		}
	}
	else
	{
		while(i<p)
		{
			a[k]=b[i];
			i++;k++;
		}
	}
}

void MergeSort(int a[],int n)
{
	if(n>1)
	{
		int m=n-n/2;
		int b[n/2],c[m];

		for(int i=0;i<n/2;i++)
			b[i]=a[i];

		for(int i=0;i<m;i++)
			c[i]=a[i+n/2];

		MergeSort(b,n/2);
		MergeSort(c,m);
		Merge(b,c,a,n/2,m);
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
	MergeSort(a,n);
	printf("Printing:  ");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i] );
}