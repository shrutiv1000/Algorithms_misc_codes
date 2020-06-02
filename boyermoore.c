#include<stdio.h>
#include<string.h>
int lookup_table[128],comp=0;
void create_ltable(char str[])
{
	int i=0,j;
	int n=strlen(str);
	while(str[i]!='\0')
	{
		j=str[i];
		lookup_table[j]=n-i-1;
		i++;
	}
	lookup_table[j]=n;
}
int max(int a,int b)
{
	return (a>b)?a:b;
}
void create_gtable(char pat[],int gst[],int n)
{
	for(int i=n-1;i>0;i--)
	{
		gst[n-i]=0;
		for(int j=i-1;j>=0;j--)
		{
			int flag=0;
			if(pat[i]==pat[j])
			{
				if(j!=0)
				{
					if(pat[j-1]==pat[i-1])
						continue;
				}for(int k=0;k<n-1-i;k++)
				{
					if(pat[k+j]!=pat[k+i]){
						flag=1;
						break;
					}
				}if(flag==0)
					gst[n-i]=i-j;
			}
		}if(gst[n-i]==0){
			if(i==n-1)
				gst[n-i]=n;
			else
				gst[n-i]=gst[n-i-1];
		}
	}
}
int search(char pat[],char text[],int gst[])
{
	int n=strlen(pat);
	int m= strlen(text);
	int i=n-1,j=n-1;
	while(i<m && j<n)
	{
		if(j<0)
			return i+1;
		comp++;
		if(text[i]!=pat[j])
		{
			int k=n-1-j,d1,d2;
			j=n-1;
			if(k==0){
				d1=max(lookup_table[text[i]],1);
				d2=0;
			}else{
				d1=max(lookup_table[text[i]]-k,1);
				d2=gst[k];
			}i+=max(d1,d2);

		}else{
			i--;
			j--;
		}
	}return -1;
}
int main()
{
	char text[50],pat[10];
	printf("Enter text: ");
	gets(text);
	printf("Enter pattern: ");
	gets(pat);
	int n=strlen(pat);
	for(int i=0;i<128;i++)
	{
		lookup_table[i]=n;
	}
	create_ltable(pat);
	int gst[n];
	create_gtable(pat,gst,n);
	/*for(int i='a';i<='z';i++)
		printf("\n%c %d",i,lookup_table[i]);
	for(int i=1;i<n;i++)
		printf("\n%d %d",i,gst[i]);*/
	int s= search(pat,text,gst);
	if(s==-1)
		printf("\nString not found.\n");
	else
		printf("\nString Found at Position %d.\n",s+1);
	printf("No. of Comparisons: %d\n\n",comp);
}