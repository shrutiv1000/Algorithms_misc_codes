#include<stdio.h>
#include<stdlib.h>
#define Max_q_Size 100
int opcount=0;
int n;
typedef struct{
	int arr[Max_q_Size];
	int front, rear;
} Q;
void init(Q *c)
{
	c->front=-1;
	c->rear=-1;
}
int isEmpty(Q *c)
{
	if(c->front==c->rear)
		return 1;
	return 0;
}
void addq(Q *c,int item)
{
	if(c->rear==Max_q_Size-1)
	{
		printf("Queue Overflow");
		exit(0);
	}
	c->arr[++c->rear]=item;
}
int deleteq(Q *c)
{
	if(c->front==c->rear){
		printf("Queue Underflow");
		exit(0);}
	return (c->arr[++c->front]);
}
void display(Q *c)
{
	printf("\n");
	for(int i=c->front+1;i<=c->rear;i++)
	{
		printf("%d\t",c->arr[i]);
	}
}
void bfs(int visited[n],Q* q,int v,int a[][n],int end){
	
	printf("\n%d",v);
	visited[v]=1;
	if(v==end)
		return;
	for(int i=0;i<n;i++)
	{	opcount++;
		if(a[v][i]!=0 && visited[i]==0)
			addq(q,i);
	}
	if(!isEmpty(q)){
		int p=deleteq(q);
		if(visited[p]==0)
			bfs(visited,q,p,a,end);
	}
	else
		return;
}

int main()
{
	printf("Enter n: ");
	scanf("%d",&n);
	int a[n][n],visited[n];
	printf("Enter adjacency matrix: ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			//printf("\nEnter adjacency for vertex %d and vertex %d: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++)
        visited[i]=0;
    Q q;
    init(&q);
    int v,end;
    printf("\nEnter starting vertex: ");
    scanf("%d",&v);
    printf("\nEnter ending vertex: ");
    scanf("%d",&end);
    bfs(visited,&q,v,a,end);
   /* for(int j=0;j<n;j++)
    {	init(&q);
      	if(visited[j]==0)
        	bfs(visited,&q,j,a);
    }*/
    printf("\nOperation Count=%d",opcount);
}