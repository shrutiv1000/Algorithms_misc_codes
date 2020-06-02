#include<stdio.h>
#include<stdlib.h>

int n;
typedef struct{
int arr[1000];
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
if(c->rear==1000-1)
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
}}
int is_present(Q *q,int x)
{
	for(int i=q->front;i<=q->rear;i++)
		if(q->arr[i]==x)
			return 1;
	return -1;
}

void bfs(int a[][n],int visited[],int color[],int i,Q *q)
{
visited[i]=1;
printf("%d\t",i );
for(int j=0;j<n;j++){
if(visited[j]==0 && a[i][j]==1 && is_present(q,j)==-1)
{
addq(q,j);
color[j]=!color[i];
}
}
while(!isEmpty(q))
{
int p=deleteq(q);
if(visited[p]==0 && a[i][p]==1 && color[p]!=color[i])
{
bfs(a,visited,color,p,q);
}
else if(visited[p]==0 && a[i][p]==0)
	bfs(a,visited,color,p,q);
else if(visited[p]==0 && a[i][p]==1 && color[p]==color[i]){
	printf("Not bipartite\n");
exit(0);
}

else if(visited[p]==1 && a[i][p]==1 && color[p]==color[i])
{
printf("Not bipartite\n");
exit(0);
}
else return;
}
}

int main()
{
Q q1,*q=&q1;
init(q);
printf("Enter n:");
scanf("%d",&n);
int a[n][n],visited[n],color[n];
for(int i=0;i<n;i++)
visited[i]=0;
printf("Enter matrix\n");
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
scanf("%d",&a[i][j]);
printf("Enter starting vertex: ");
int p;
scanf("%d",&p);
color[p]=1;
bfs(a,visited,color,p,q);
for(int i=0;i<n;i++)
if(visited[i]==0)
{
printf("Not connected\n");
exit(0);
}
printf("\nPartitions:\n");
for(int i=0;i<n;i++)
if(color[i]==1)
printf("%d\t",i);

printf("\n");
for(int i=0;i<n;i++)
if(color[i]==0)
printf("%d\t",i );
}