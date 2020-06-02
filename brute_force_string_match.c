#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int opcount=0;
//n2>n1
int match(char str1[],char str2[])
{
	int n1,n2,flag=0;
	n1=strlen(str1);
	n2=strlen(str2);
	for(int i=0;i<=n2-n1;i++)
	{
		int j;
		for (j = 0; j < n1; j++) {opcount++;
       // printf("\n%c %c",txt[i+j],pat[j]);
            if (str2[i + j] != str1[j]) 
                break; }
  
        if (j == n1) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
           return i;
    } 
    return -1;
}
int main()
{
	int n;
	char str1[50],str2[50];
	printf("Enter the two strings: ");
	scanf(" %s", str1);
	scanf(" %s", str2);
	if(strlen(str1)>strlen(str2))
		n=match(str2,str1);
	else
		n=match(str1,str2);
	if(n!=-1)
		printf("String Matched at index %d\n",n+1);
	else
		printf("String did not match\n");
	printf("\nOperation Count: %d\n",opcount);
}