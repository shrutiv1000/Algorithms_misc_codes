#include<stdio.h>
#include<stdlib.h>
typedef struct stck{
	int data[100];
	int top;
} stck;
int opcount=0,n;
int push(stck *s,int x)
{
	return(s->data[++s->top]=x);
}
int pop(stck *s)
{
	return(s->data[s->top--]);
}
void print_rev(stck *s)
{
	for(int i=0;i<=s->top;i++)
		printf("\t%d",s->data[i]);
}
void DFS(int i,int visited[],int a[][n],stck *s,int end)
{
  int j;
  push(s,i);
  visited[i]=1;
  if(i==end)
  	return;
  for(j=0;j<n;j++){
    opcount++;
    if(!visited[j]&&a[i][j]==1)
       DFS(j,visited,a,s,end);
  }
}   
void main()
{
  int i,j;
  printf("Enter number of vertices in maze:");
	scanf("%d",&n);
  int a[n][n],visited[n];
	printf("\nEnter adjecency matrix of the maze:");
	for(i=0;i<n;i++)
       for(j=0;j<n;j++){
			  scanf("%d",&a[i][j]);
      }
   for(i=0;i<n;i++)
        visited[i]=0;
    stck s;
    s.top=-1;
    printf("Enter the node to start: ");
    int p,q;
    scanf("%d",&p);  
    printf("Enter the node to end: ");
    scanf("%d",&q);
    DFS(p,visited,a,&s,q);
    if(pop(&s)==q){
    	printf("Path: ");
    	print_rev(&s);
    }
    printf("\nOperation Count=%d",opcount);
}
