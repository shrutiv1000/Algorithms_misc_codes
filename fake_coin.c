#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of coins: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the coins: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int p,q,found=0,pos,size,l=0,r=n-1;
	while(found!=1)
	{
		size=r+1-l;
		p=size%3;
		q=size/3;
		if(q==0)
		{
			for(int i=l;i<=r;i++)
			{
				if(arr[i]==11)
				{
					found=1;
					pos=i;
					break;
				}
			}if(found==0)
			{
				printf("No Fake Coin.");
				found=1;
				pos=-2;
			}
		}else{
			int sum1=0,sum2=0,sum3=0;
			for(int i=l;i<=r;i++)
			{
				if(i<l+q)
					sum1=sum1+arr[i];
				else if(i<l+(2*q))
					sum2=sum2+arr[i];
				else
					sum3=sum3+arr[i];
			}
			sum1=sum1%q;
			sum2=sum2%q;
			sum3=sum3%(p+q);
			if(sum1==sum2)
			{
				r=r;
				l=l+(2*q);
			}
			else if(sum1==sum3)
			{
				r=l+(2*q)-1;
				l=l+q;
			}
			else
			{
				l=l;
				r=l+q-1;
			}
		}}
	
	printf("\nCoin found at position %d",pos+1);
}