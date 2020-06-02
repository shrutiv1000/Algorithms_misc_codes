#include <stdio.h>
#include <stdlib.h>

int count=0;

typedef struct node* Nodeptr;

struct node{
	int data;
	Nodeptr lchild,rchild;
};

Nodeptr getnode(){
	Nodeptr temp=(Nodeptr)malloc(sizeof(struct node));
	temp->rchild=temp->lchild=NULL;
	return temp;
}

Nodeptr create(Nodeptr root,int data)
{
	if(!root)
	{
		Nodeptr temp=getnode();
		temp->data=data;
		return temp;
	}
	if(data<root->data)
		root->lchild=create(root->lchild,data);
	else if(data>root->data)
		root->rchild=create(root->rchild,data);
	return root;
}

void inorder(Nodeptr root)
{
	if(root)
	{
		count++;
		inorder(root->lchild);
		printf("%d\t",root->data);
		inorder(root->rchild);
	}
}


int main()
{
	Nodeptr root=NULL;
	int x,n;
	printf("Enter no. of nodes\n");
	scanf("%d",&n);
	printf("Enter nodes\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		root=create(root,x);
	}
	printf("Inorder: ");
	inorder(root);
	printf("\nNo of nodes: %d",count);


}