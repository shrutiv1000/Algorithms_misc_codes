#include <stdio.h>

int n;
int order[100];

void Print(int arr[][n])
{
	printf("Printing matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",arr[i][j] );
		printf("\n");
	}

}
void TS(int a[][n])
{
	int count=0;
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			int flag=0;
			for(int j=0;j<n;j++)
			{
				if(a[j][i]!=0)
				{ 
					flag=1;
					break; 
				}
			}
			if(flag==0)
			{
				order[count++]=i;
				for(int j=0;j<n;j++)
					a[i][j]=0;
				a[i][i]=-1;
				break;
			}
		}
	}
	if(count!=n)
	{
		printf("Not possible\n");
		return;
	}
	for(int i=0;i<n;i++)
		printf("%d \t",order[i]+1);

}

int main()
{
	int x=0;
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	int arr[n][n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j]=0;

	for(int i=0;i<n;i++)
	{
		printf("Enter vertices adjacent to %d [-1 to exit]\n",i+1);
		x=0;
		while(x!=-1)
		{
			scanf("%d",&x);
			if(x!=(i+1) && x>0 && x<=n)
				arr[i][x-1]=1;
		}
	}
	TS(arr);
}