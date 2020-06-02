#include <stdio.h>
#include <string.h>

int main()
{
  char text[100], pat[100];
  int i,j;
  printf("Enter string: ");
  gets(text);
  printf("Enter pattern: ");
  gets(pat);
  int m=strlen(text);
  int n=strlen(pat);
  for(i=0;i<=m-n;i++)
  {
  	for(j=0;j<n;j++)
  		if(pat[j]!=text[i+j])
  			break;
  	if(j==n)
  		break;
  }
  if(j==n)
  	printf("Patten found at %d\n",i+1);
  else
  	printf("Not found\n");
	
}