#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	return (a>b)?a:b;
}
int main()
{
	char text[50],pat[10];
	printf("Enter text: ");
	gets(text);
	printf("Enter pattern: ");
	gets(pat);
	int badmatchtable[27];
	int textlen=strlen(text);
	int patlen=strlen(pat);
	for(int i=0;i<26;i++)
		badmatchtable[i]=patlen;
	for(int i=0;i<patlen;i++)
		badmatchtable[pat[i]-'a']=max(1,patlen-i-1);
	badmatchtable[26]=patlen;
	int goodsufftable[patlen];
	printf("H");
	for(int i=patlen-1;i>0;i--)
	{
		int flag=0;
		for(int j=i-1;j>=0;j--)
		{
			if(pat[j]==pat[i])
			{
				int f=0;
				for(int k=0;k<patlen-i;k++)
				{
					if(pat[k+i]!=pat[j+i])
						f=1;
				}
				if(f==0){
					flag=1;
					goodsufftable[i]=i-j;
					break;
				}else{
					if(i==patlen-1)
						goodsufftable[i]=patlen;
					else
						goodsufftable[i]=goodsufftable[i+1];
				}
			}
		}if(flag==1){
			break;
		}else{
			if(i==patlen-1)
				goodsufftable[i]=patlen;
			else
				goodsufftable[i]=goodsufftable[i+1];}
	}
	printf("\nBad Match Table: \n");
	for(int i=0;i<26;i++)
		printf("%c - %d\t",'a'+i,badmatchtable[i]);
	printf("\nGood Suffix Table: \n");
	for(int i=1;i<=patlen-1;i++)
		printf("%c - %d\t",pat[i],goodsufftable[i]);
}