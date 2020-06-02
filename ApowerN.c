#include <stdio.h>


int Divide(int a,int n)
{
	if(n=1)
		return n;
	return Divide(a,n/2)*Divide(a,n-n/2);
}

int main()
{
	int a,n;
	printf("a: ");
	scanf("%d",&a);
	printf("n: ");
	scanf("%d",&n);
	printf("a^n = %d \n",Divide(a,n) );
	
}