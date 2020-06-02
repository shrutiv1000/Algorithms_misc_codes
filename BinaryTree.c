#include <stdio.h>
#include<stdlib.h>

typedef struct node* Nodeptr;

struct node{
	int data;
	Nodeptr lchild,rchild;
};

Nodeptr getnode(){
	Nodeptr temp=(Nodeptr)malloc(sizeof(struct node));
	temp->rchild=NULL;
	temp->lchild=NULL;
	return temp;
}

void preorder(Nodeptr root)
{
	if(root)
	{
		printf("%d\t",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void inorder(Nodeptr root)
{
	if(root)
	{
		inorder(root->lchild);
		printf("%d\t",root->data);
		inorder(root->rchild);
	}
}

void postorder(Nodeptr root)
{
	if(root)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d\t",root->data);
	}
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
	else
		printf("Key Found\n");
	return root;
}



int main()
{
	Nodeptr root=NULL;
	int x=0,i;
	while(x!=5)
	{
		printf("Choose one of the following:\n1.Insert\t2.Inorder\t3.Preorder\t4.Postorder\t5.Exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("x: ");
				scanf("%d",&i);
				root=create(root,i);
				break;
			case 2:printf("Inorder: ");inorder(root);printf("\n");break;
			case 3:printf("Preorder: ");preorder(root);printf("\n");break;
			case 4:printf("Postorder: ");postorder(root);printf("\n");break;
			case 5:break;
			default:printf("Invalid Entry!!\n");
		}	
	}
}