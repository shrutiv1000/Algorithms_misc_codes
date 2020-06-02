#include<stdio.h>
#include<stdlib.h>

typedef struct list * listPointer;

typedef struct list{
	char data;
	listPointer link;
} list;


void insertR(listPointer* front,char n)
{
	listPointer temp,a;
	a=*front;
	temp=malloc(sizeof(list));
	temp->data=n;
	if(*front == NULL)
	{
		temp->link=NULL;
		*front=temp;
	}else{
		while(a->link!=NULL)
			a=a->link;
		temp->link=NULL;
		a->link=temp;
	}
}

void print(listPointer first)
{
	listPointer a;
	a=first;
	printf("%c",a->data);
	a=a->link;
	while(a)
	{
		printf(" -> %c",a->data);
		a=a->link;
	}
}
int find(listPointer a,char b)
{
	a=a->link;
	while(a!=NULL)
	{
		if(a->data==b)
			return 1;
		else 
			a=a->link;
	}
	return 0;
}
void createMatrix(listPointer arrv[],int n, char v[])
{
	int arr[n][n];
	/*printf("\n\t");
	for(int i=0;i<n;i++)
		printf("%c\t",v[i]);*/
	for(int i=0;i<n;i++)
	{
		//printf("\n%c\t",arrv[i]->data);
		for(int k=0;k<n;k++)
		{
			if(find(arrv[i],v[k]))
				arr[i][k]=1;
			else
				arr[i][k]=0;
		}
	}
	printf("\n\t");
	for(int i=0;i<n;i++)
		printf("%c\t",v[i]);
	for(int i=0;i<n;i++)
	{
		printf("\n%c\t",arrv[i]->data);
		for(int j=0;j<n;j++)
		{
			printf("%d\t",arr[i][j]);
		}
	}
}
void createList(char v[],char e[][2],int n,int i)
{
	//printf("here");
	listPointer arrv[n];
	for(int j=0;j<n;j++)
	{
		arrv[j]=malloc(sizeof(list));
		arrv[j]->data=v[j];
		arrv[j]->link=NULL;
		for(int k=0;k<i;k++)
		{
			if(e[k][0]==v[j])
			{
				insertR(&arrv[j],e[k][1]);
			}
		}
	}
	for(int j=0;j<n;j++){
		print(arrv[j]);
		printf("\n");
	}
	createMatrix(arrv,n,v);
}
int main()
{
	int n;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	char v[n];
	printf("Enter the vertices: ");
	for(int i=0;i<n;i++)
	{
		scanf(" %c", &v[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%c\t",v[i]);
	//int d =(n*(n-1));
	/*char e[d][2];
	int p;
	/*do{
		printf("Enter 1 to insert an edge. Enter 2 to exit. ");
		scanf("%d",&p);
		printf("\n %d %d \n",i,p);
		if(p==1)
		{
			scanf(" %c",&e[i][0]);
			scanf(" %c",&e[i][1]);
			i++;
		}
	} while(p==1);*/
	int d;
	printf("Enter number of edges: ");
	scanf("%d",&d);
	char e[d][2];
	printf("Enter the edges: ");
	for(int i=0;i<d;i++)
	{
		scanf(" %c",&e[i][0]);
		scanf(" %c",&e[i][1]);
	}
	for(int i=0;i<d;i++)
	{
		printf("%c %c \n",e[i][0],e[i][1]);
	}
	createList(v,e,n,d);
}