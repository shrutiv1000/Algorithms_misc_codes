#include <string.h>
#include <stdio.h>

int count=0;

void ShiftTable(char p[],int m,int table[],int size)
{
	for(int i=0;i<size;i++)
		table[i]=m;
	for(int i=0;i<m-1;i++)
		table[p[i]]=m-i-1;
}

int Horspool(char t[],int n,char p[],int m)
{
	int table[128];
	ShiftTable(p,m,table,128);
	int i=m-1;
	while(i<n)
	{
		int k=0;
		while(k<m && ++count && p[m-1-k]==t[i-k])
		{
			k++;
		}
		if(k==m)
			return i-m+1;
		else i+=table[t[i]];
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
  int x=Horspool(text,n,pat,m);
  if(x!=-1)
  	printf("Found at %d\n",x);
  else
  	printf("Not found\n");
  printf("Total comparision: %d \n",count );

}