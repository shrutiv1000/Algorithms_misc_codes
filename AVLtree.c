#include<stdio.h>
#include <stdlib.h>
#include "header.h"

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
	if(!root) return;
	root->bf=height(root->lchild)-height(root->rchild);
	BalanceFactor(root->lchild);
	BalanceFactor(root->rchild);
}

Nodeptr rightRotate(Nodeptr y) 
{ 
    Nodeptr x = y->lchild; 
    Nodeptr T2 = x->rchild; 
    x->rchild = y; 
    y->lchild = T2;
    BalanceFactor(x);
    BalanceFactor(y);
    return x; 
} 
  
Nodeptr leftRotate(Nodeptr x) 
{ 
    Nodeptr y = x->rchild; 
    Nodeptr T2 = y->lchild; 
    y->lchild = x; 
    x->rchild = T2; 
    BalanceFactor(x);
    BalanceFactor(y);
    return y; 
} 
Nodeptr insert(Nodeptr node, int data) 
{ 
	if(!node)
	{
		Nodeptr root=getnode();
		root->data=data;
		return root;
	}
	
	if(data<node->data)
		node->lchild=insert(node->lchild,data);
	else if(data>node->data)
		node->rchild=insert(node->rchild,data);
	else
		return node;
	
   	BalanceFactor(node);
  
    if (node->bf > 1 && data < node->lchild->data) 
        return rightRotate(node); 
  
    if (node->bf < -1 && data > node->rchild->data) 
        return leftRotate(node); 
  
    if (node->bf > 1 && data > node->lchild->data) 
    { 
        node->lchild =  leftRotate(node->lchild); 
        return rightRotate(node); 
    } 
  
    if (node->bf < -1 && data < node->rchild->data) 
    { 
        node->rchild = rightRotate(node->rchild); 
        return leftRotate(node); 
    } 
    return node; 
} 


void inorder(Nodeptr root){
	if(root)
	{
		inorder(root->lchild);
		printf("%d\t %d\n",root->data,root->bf);
		inorder(root->rchild);
	}
}

int main()
{
	int x;
	Nodeptr root=NULL;
	printf("x: ");
	scanf("%d",&x);
	while(x!=-1)
	{
		root=insert(root,x);
		BalanceFactor(root);

    inorder(root);
		printf("x: ");
		scanf("%d",&x);
	}		
	printf("Root\tBal_Fact\n");
	inorder(root);
}