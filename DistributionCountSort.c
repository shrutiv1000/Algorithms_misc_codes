#include <stdio.h>

void Sort(int a[],int n)
{
	int u,l,i;
	u=l=a[0];
	for(i=1;i<n;i++)
	{
		if(u<a[i])
			u=a[i];
		if(l>a[i])
			l=a[i];
	}
	int d[u-l+1],s[n];
	for(i=0;i<=u-l;i++)
		d[i]=0;
	for(i=0;i<n;i++)
		d[a[i]-l]++;
	for(i=1;i<=u-l;i++)
		d[i]+=d[i-1];
	for(i=n-1;i>=0;i--)
	{
		int j=a[i]-l;
		s[d[j]-1]=a[i];
		d[j]--;
	}
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