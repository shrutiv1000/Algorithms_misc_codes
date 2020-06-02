#include<stdio.h>
#include<stdlib.h>
typedef struct que{
	int arr[100];
	int rear,front;
} que;
int n;
void init(que *q)
{
	q->front=-1;
	q->rear=-1;
}
int isEmpty(que *q)
{
	if(q->front==q->rear)
		return 1;
	return 0;
}
void addq(que *q,int x)
{
	q->arr[++q->rear]=x;
	return;
}
int delq(que *q)
{
	int x=q->arr[++q->front];
	return x;
}
int isPresent(que *q,int x)
{
	for(int i=q->front+1;i<=q->rear;i++)
	{
		if(q->arr[i]==x)
			return 1;
	}
	return 0;
}
void bfs(int arr[][n],int v,int visited[],que *q,int color[n])
{
	visited[v]=1;
	printf("%d\t",v);
	for(int i=0;i<n;i++)
	{
		if(visited[i]!=1 && arr[v][i]==1 && isPresent(q,i)==0){
			addq(q,i);
			color[i]=!color[v];
		}
	}
	if(!isEmpty(q))
	{
		int p=delq(q);
		if(visited[p]==0 && arr[v][p]==1 && color[v]!=color[p])
			bfs(arr,p,visited,q,color);
		else if(visited[p]==0 && arr[v][p]==0 && color[v]==color[p])
			bfs(arr,p,visited,q,color);
		else
		{
			printf("Not a bipartite graph.");
			exit(0);
		}

	}
}
int main()
{
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int arr[n][n],visited[n],p,color[n];
	printf("Enter adjacency matrix: ");
	for(int i=0;i<n;i++){
		visited[i]=0;
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	}
	printf("Enter the node to start: ");
	scanf("%d",&p);
	que q;
	init(&q);
	color[p]=1;
	bfs(arr,p,visited,&q,color);
	printf("\nBipartite Graph: \nPart 1:");
	for(int i=0;i<n;i++)
	{
		if(color[i]==1)
			printf(" %d",i);
	}
	printf("\nPart 2:");
	for(int i=0;i<n;i++)
	{
		if(color[i]==0)
			printf(" %d",i);
	}
}