#include<stdio.h>
#include "header.h"

Nodeptr insert(Nodeptr root,int x){
	if(root){
		if(x<root->data)
			root->lchild=insert(root->lchild,x);
		else if(x>root->data)
			root->rchild=insert(root->rchild,x);
		return root;
	}
	else
	{
		Nodeptr leaf=getnode();
		leaf->data=x;
		return leaf;
	}
}


void inorder(Nodeptr root){
	if(root)
	{
		inorder(root->lchild);
		printf("%d\t",root->data);
		inorder(root->rchild);
	}
}

int max(int a,int b){
	return a>b?a:b;
}
int height(Nodeptr root){
	if(!root)
		return 0;
	return 1+max(height(root->lchild),height(root->rchild));
}

int diameter(Nodeptr root)
{
	if(!root)
		return 0;
	int rh=height(root->rchild);
	int lh=height(root->lchild);
	int rd=diameter(root->rchild);
	int ld=diameter(root->lchild);
	return max(rh+lh+1,max(rd,ld));
}

int main()
{
	int x=0;
	Nodeptr root=NULL;
	printf("CREATING TREE\n");
	printf("Enter node: ");
	scanf("%d",&x);
	while(x!=-1)
	{		
		root=insert(root,x);
		printf("Enter node: ");
		scanf("%d",&x);		
	}
	inorder(root);
	printf("\nDiameter: %d\n",diameter(root) );
}