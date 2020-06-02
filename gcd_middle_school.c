#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int opcount=0;
int givemin(int m,int n)
{
	if(m==n)
		return m;
	else
		return((m>n)?n:m);
}
int giveprimefactors(int num,int arr[]){
	 int i, j, isPrime,k=0;
	 //printf("\nheref1\n");
	while(num>1)
	{opcount++;
		//printf("\n%d",num);
		for(i=2; i<=num; i++)
    {
        if(num%i==0)
        {
            isPrime = 1;
            for(j=2; j<=i/2; j++)
            {
                if(i%j==0)
                {
                    isPrime = 0;
                    break;
                }
            }

            if(isPrime==1)
            {
            	num=num/i;
                arr[k]=i;
                k=k+1;
                break;
            }
        }
	}
   
    }return k;
}
int gcdmiddleschoolmethod(int m,int n)
{
	int prm[100],prn[100],prc[100];
	int cm,cn,i,j=0,cmin,cmax,k=0,gcd=1;
	cm=giveprimefactors(m,prm);/*
	printf("\nprm");
	for(i=0;i<cm;i++)
	{
		printf("\t%d",prm[i]);
	}*/
	//printf("\nheref2\n");
	cn=giveprimefactors(n,prn);/*
	printf("\nprn");
	for(i=0;i<cn;i++)
	{
		printf("\t%d",prn[i]);
	}*/
	//printf("\nheref2\n");
	cmin=givemin(cm,cn);
	cmax=(cmin==cm?cn:cm);
	//printf("\nheref2\n");
	prc[k]=1;
	k=k+1;
	for(i=0,j=0;i<cmin&&j<cmax;i++)
	{//printf("\nheref2\n");
opcount++;
		if(cmin==cm)
		{
			while(1&&j<cmax)
			{
				if(prm[i]==prn[j])
				{
					prc[k]=prm[i];
					k=k+1;
					break;
				}
				j=j+1;
			}
		}
		else{
			while(1&&j<cmax)
			{
				if(prn[i]==prm[j])
				{
					prc[k]=prn[i];
					k=k+1;
					break;
				}
				j=j+1;
			}
		}
	}printf("\n");
	/*for(i=0;i<k;i++)
	{
		printf("\t%d",prc[i]);
	}*/
	for(i=0;i<k;i++)
	{opcount++;
		gcd=gcd*prc[i];
	}
	return gcd;
}
int main()
{
	int n,m,gcd;
	clock_t start,end;
	printf("Enter 2 numbers: ");
	scanf("%d %d",&m,&n);
	start=clock();
	gcd=gcdmiddleschoolmethod(m,n);
	end=clock();
	double timeelapsed=((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nOperation Count: %d",opcount);
	printf("\nThe GCD of %d and %d is %d in time %f\n",m,n,gcd,timeelapsed);
	return 0;
}