#include<stdio.h>
#include "header.h"

Nodeptr insert(Nodeptr root,int x){
	if(root){
		if(x<root->data)
			root->lchild=insert(root->lchild,x);
		else if(x>root->data)
			root->rchild=insert(root->rchild,x);
		else		
			printf("Key found");
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
		printf("%d\t %d\n",root->data,root->bf );
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

void BalanceFactor(Nodeptr root)
{
	if(root)
	{
		root->bf=height(root->lchild)-height(root->rchild);
		BalanceFactor(root->lchild);
		BalanceFactor(root->rchild);
	}
	
}
int main(){
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
	BalanceFactor(root);
	printf("Root\tBal_Fact\n");
	inorder(root);
}