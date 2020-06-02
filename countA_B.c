#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
int main()
{
	char str[50];
	printf("Enter the String: ");
	gets(str);
	int count=0,countA=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='A'||str[i]=='a')
			countA++;
		else if(str[i]=='B'||str[i]=='b')
			count=count+countA;
	}
	printf("The number of required strings is: %d",count);
}