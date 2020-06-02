#include<stdio.h>
#include <stdlib.h>

typedef struct node* Nodeptr;
struct node{
	int data;
	Nodeptr link;
};
Nodeptr getnode(int x)
{
	Nodeptr temp=(Nodeptr)malloc(sizeof(struct node));
	temp->data=x;
	temp->link=NULL;
	return temp;
}

void Print(Nodeptr root)
{
	while(root->link)
	{
		printf("%d -> ",root->data);
		root=root->link;
	}
	printf("%d\n",root->data);
}

void insert(Nodeptr root,int x)
{
	while(root->link)
		root=root->link;
	root->link=getnode(x);
}
int main()
{
	int m,n,x;
	printf("m: ");
	scanf("%d",&m);
	printf("n: ");
	scanf("%d",&n);
	Nodeptr table[m];
	for(int i=0;i<m;i++)
		table[i]=getnode(i);
	printf("Enter keys\n");
	for(int i=0;i<n;i++)
	{
		printf("x: ");
		scanf("%d",&x);
		insert(table[x%m],x);
	}
	printf("Printing:\n");
	for(int i=0;i<m;i++)
		Print(table[i]);

}