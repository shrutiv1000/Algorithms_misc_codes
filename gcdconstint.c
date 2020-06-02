#include<stdio.h>
#include<stdlib.h>
#include<time.h>
	int opcount=0;
int givemin(int m,int n)
{
	return((m>n)?n:m);
}
int gcdconsintmethod(int n,int m)
{
	if(m==0||n==0){
		opcount++;
		//printf("Operation Count: %d",opcount);
		return 1;
	}
	int t=givemin(n,m);
	while(1){
		//printf("1");
		opcount++;
		if(m%t==0)
		{
			
			if(n%t==0){
				return t;
			}
			else
				t=t-1;
		}else
			t=t-1;
	}
}
int main()
{
	int n,m,gcd;
	clock_t start,end;
	printf("Enter 2 numbers: ");
	scanf("%d %d",&m,&n);
	start=clock();
	gcd=gcdconsintmethod(m,n);
	end=clock();
	double timeelapsed=((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Operation Count: %d",opcount);
	printf("\nThe GCD of %d and %d is %d in time %f\n",m,n,gcd,timeelapsed);
	return 0;
}