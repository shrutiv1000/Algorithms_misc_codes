#include <stdio.h>

void Sort(int a[],int n)
{
	int i,j,count[n],s[n];
	for(i=0;i<n;i++)
		count[i]=0;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]<a[j])
				count[j]++;
			else
				count[i]++;
	for(i=0;i<n;i++)
		s[count[i]]=a[i];
	for(i=0;i<n;i++)
		a[i]=s[i];
}


int main(){
	int n,i,j;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	Sort(a,n);
	printf("List: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i] );
}