#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;

int max(int arr[])
{
	int m=0;
	for(int i=0;i<n;i++)
		if(m<arr[i])
			m=arr[i];
	return m;
}

int copy(char a[],char b[])
{
	int i;
	for(i=0;b[i]!='\0';i++)
		a[i]=b[i];
	a[i]='\0';
}

void print(char str[][100])
{
	printf("Printing:::\n");
	for(int i=0;i<n;i++)
	{
		puts(str[i]);
	}
}
int checkPrev(char a[],char b[],int k)
{
	for(int i=0;i<k;i++)
		if(a[i]!=b[i])
			return 0;
	return 1;
}
int main()
{
	printf("Enter no. of string: ");
	scanf("%d",&n);
	char str[n][100],s[100];
	int len[n];

	printf("Enter the strings\n");
	gets(str[0]);
	for(int i=0;i<n;i++)
	{
		gets(str[i]);
		len[i]=strlen(str[i]);
	}

	int m=max(len);

	for(int k=0;k<m;k++)
	{
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				if(len[j]>k && ((k==0||checkPrev(str[j],str[j+1],k)) && str[j][k]>str[j+1][k])||(len[j+1]<=k && checkPrev(str[j],str[j+1],len[j+1])))
				{
					copy(s,str[j]);
					copy(str[j],str[j+1]);
					copy(str[j+1],s);
					int l=len[j];
					len[j]=len[j+1];
					len[j+1]=l;
				}

			}
		}
	}

	print(str);
	
}