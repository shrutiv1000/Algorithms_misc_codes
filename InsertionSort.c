#include<stdio.h>
int n;
void Sort(int a[])
{
	for(int i=1;i<n;i++)
	{
		int v=a[i];
		int j=i-1;
		while(j>=0 && a[j]>=v)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
	}
}

int main()
{
	printf("Enter n:");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	Sort(a);
	printf("Sorted elements\n");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
}