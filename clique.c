#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
int powerset(int arr[][n])
{
	int t=pow(2,n);
	int k=0;
	for(int i=0;i<t;i++)
	{
		k=0;
		for(int j=0;j<n;j++)
		{
			if((i >> j) & 1)
			{
				arr[i][k++]=j;
			}
			else
				arr[i][k++]=-1;
		}
	}
}
int main()
{
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int t=pow(2,n);
	int arr[t][n];
	powerset(arr);
	int matrix[n][n];
	printf("Enter adjacency matrix of graph: ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n;j++)
			if(arr[i][j]!=-1)
				printf("%d\t",arr[i][j]);
		printf("\n");
	}
	int max=0,maxi=0,temp[n],k=0,found=0;
	for(int i=0;i<t;i++)
	{
		k=0;
		found=0;
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]!=-1)
			{
				temp[k]=arr[i][j];
				k=k+1;
			}
		}
		//printf("\ni=%d k=%d",i,k);
		if(k>1)
		{
			for(int l=0;l<k;l++)
			{	//printf(" %d",temp[l]);
				if(matrix[temp[l]][temp[l]]!=0){
					found=0;
					break;
				}
				for(int a=0;a<k;a++)
				{
					if(a!=l){
					if(matrix[temp[l]][temp[a]]!=1){
						//printf("\tl=%d a=%d m=%d",l,a,matrix[temp[l]][temp[a]]);
						found=0;
						break;
					}
					found=1;}
				}
				if(found==0)
					break;
			}
			if(found==1)
				{
					if(k>max){
						maxi=i;
						max=k;
					}
				}
		}
	}
	if(max>0)
	{
		printf("\nClique Size = %d\nClique: ",max);
		for(int i=0;i<n;i++){
			if(arr[maxi][i]!=-1)
			{
				printf("%d ",arr[maxi][i]);
			}
		}
	}
	else{
		printf("Clique size = 1");
	}
}