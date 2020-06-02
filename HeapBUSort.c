#include<stdio.h>
#include<stdlib.h>

int check(int a[],int n)
{
	for(int i=1;i<n;i++)
	 	if(a[i]==a[n])
	 		return 1;
	 return 0;
}
void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void BottomUp(int a[],int n,int flag,int x)
{
	int i,c;
	i=(flag==1?1:n/2);
	while(2*i<=n)
	{
		if(2*i+1<=n)
		{
			if(x==1)
				c=a[2*i]>a[2*i+1]?2*i:2*i+1;
			else
				c=a[2*i]<a[2*i+1]?2*i:2*i+1;
		}
		else
			c=2*i;
		if(x==1)
		{
			if(a[i]<a[c])
				swap(a,i,c);
		}
		else
		{
			if(a[i]>a[c])
				swap(a,i,c);
		}

		if(i==1)
			flag=1;
		i=(flag==1?c:i-1);
	}
}

void Sort(int a[],int n,int x)
{
	for(int i=n;i>1;i--)
	{
		BottomUp(a,i,1,x);
		swap(a,i,1);
	}
}
void SortR(int a[],int n,int x)
{
	if(n==1)
		return;
	BottomUp(a,n,1,x);
	swap(a,n,1);
	SortR(a,n-1,x);
}

int main(){
	int n,i,j,x;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	int a[n+1];
	a[0]=0;
	printf("Enter elements\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(check(a,i))
		{
			printf("Duplicate entry\n");
			i--;
		}
	}
	printf("Enter 1)Ascending  2)Descending [default:Descending] : ");
	scanf("%d",&x);
	BottomUp(a,n,0,x);
	printf("\nList: ");
	for(i=1;i<=n;i++)
		printf("%d\t",a[i] );
	SortR(a,n,x);
	printf("\nList: ");
	for(i=1;i<=n;i++)
		printf("%d\t",a[i] );
}