#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[90]={0};
	for(int i=0;i<99;i++)
	{
		int n=rand()%90;
		while(arr[n]==1)
			n=rand()%90;
		printf("\n%d",n+1);
		arr[n]=1;
		for(long int j=0;j<99999999;j++);
		for(long int j=0;j<99999999;j++);
		for(long int j=0;j<99999999;j++);
		for(long int j=0;j<99999999;j++);
		for(long int j=0;j<99999999;j++);
	}
}