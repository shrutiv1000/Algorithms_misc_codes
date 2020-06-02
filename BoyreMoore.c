#include <string.h>
#include <stdio.h>

int count=0;

int max(int a,int b){
	return a>b?a:b;
}

void ShiftTable(char p[],int m,int table[],int size)
{
	for(int i=0;i<size;i++)
		table[i]=m;
	for(int i=0;i<m-1;i++)
		table[p[i]]=m-i-1;
}

void GoodSuffix(char p[],int m,int table[])
{
	int i;
	table[0]=0;
	for(i=1;i<m;i++)
		table[i]=m;
	i=1;
	while(i<m)
	{
		int k=1;
		while(k<m)
		{
			int j=0,x=k;
			while(j<i && (m-x)>0 && p[m-1-j]==p[m-1-x])
			{
				j++;x++;
			}
			if((j==i && p[m-1-j]!=p[m-1-x])||x==m)
			{
				table[i]=k;	
				break;
			}
			k++;
		}
		i++;
	}
}

int BoyreMoore(char txt[],int n,char p[],int m)
{
	int t[128],d2[m];
	ShiftTable(p,m,t,128);
	GoodSuffix(p,m,d2);
	printf("Prinitng good suffix: \t");
	for(int j=0;j<m;j++)
		printf("%d\t",d2[j] );
	printf("\n");
	int i=m-1;
	while(i<n)
	{
		int k=0;
		while(k<m && ++count && p[m-1-k]==txt[i-k])
		{
			k++;
		}
		if(k==m)
			return i-m+1;
		else 
		{
			int d1=max(t[txt[i-k]]-k,1);
			i+=max(d1,d2[k]);
		}
	}
	return -1;
}

int main()
{
  char text[100], pat[100];
  int i,j;
  printf("Enter string: ");
  gets(text);
  printf("Enter pattern: ");
  gets(pat);
  int n=strlen(text);
  int m=strlen(pat);
  int x=BoyreMoore(text,n,pat,m);
  if(x!=-1)
  	printf("Found at %d\n",x);
  else
  	printf("Not found\n");
  printf("Total comaprisions: %d \n",count );

}