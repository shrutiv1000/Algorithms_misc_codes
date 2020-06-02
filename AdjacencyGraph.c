#include<stdio.h>
#include<stdlib.h>

typedef struct node* Nodeptr;

struct node{
	int data;
	Nodeptr link;
};

Nodeptr getnode()
{
	Nodeptr temp=(Nodeptr)malloc(sizeof(struct node));
	temp->link=NULL;
	return temp;
}

/*void initialize(int arr[100][100],int n)
{
	for(int i=0;i<n;i++)
	{
	printf("Entered%d\n",i);
		for(int j=0;j<n;j++)
		{
			printf("Done%d\n",j);
			arr[i][j]=0;
			printf("whyy\n");
		}

		printf("Exited\n");
	}
}*/

void insert(Nodeptr root,int x)
{
	Nodeptr temp=getnode();
	temp->data=x;
	while(root->link)
		root=root->link;
	root->link=temp;
}

void Print(Nodeptr root)
{
	printf("%d ",root->data );
	if(root->link)
	{
		printf("-> ");
		Print(root->link);
	}
	else
		printf("\n");

}

int main()
{
	int n,x=0;
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	int arr[n][n];
	//initialize(arr,n);
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
	printf("Printing matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",arr[i][j] );
		printf("\n");
	}

	Nodeptr list[n];
	for(int i=0;i<n;i++)
	{
		list[i]=getnode();
		list[i]->data=i+1;

		for(int j=0;j<n;j++)
			if(arr[i][j]==1)
				insert(list[i],j+1);
	}
	printf("Printing list\n");
	for(int i=0;i<n;i++)
		Print(list[i]);
}