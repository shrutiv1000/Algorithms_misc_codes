#include<stdio.h>
#include<stdlib.h>
typedef struct Node* Nodeptr;
typedef struct Node{
	int key;
	Nodeptr left,right;
}Node;
int count_nodes(Nodeptr root)
{
	if(root)
		return(1+count_nodes(root->left)+count_nodes(root->right));
	else
		return 0;
}
void insert_NormalBalanced(Nodeptr* root,int key)
{
	Nodeptr temp=(Nodeptr)malloc(sizeof(Node));
	temp->key=key;
	temp->left=temp->right=NULL;
	if(*root==NULL)
	{
		*root=temp;
		return;
	}
	Nodeptr trav=*root;
	while(trav->left && trav->right)
	{
		if(count_nodes(trav->left)==count_nodes(trav->right))
			trav=trav->left;
		else if((count_nodes(trav->left)-1)%2 != 0)
			trav=trav->left;
		else
			trav=trav->right;
	}
	if(trav->left)
	{
		trav->right=temp;
		return;
	}else{
		trav->left=temp;
	}
	return;
}
void inorder(Nodeptr root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\t",root->key);
		inorder(root->right);
	}
}
Nodeptr heapify(Nodeptr root)
{
	if(root->left==NULL && root->right==NULL)
		return root;
	Nodeptr l=heapify(root->left);
	if(root->right)
	{
		Nodeptr r=heapify(root->right);
		if(r->key > root->key &&(r->key > l->key)){
			int temp=root->key;
			root->key=r->key;
			r->key=temp;
			heapify(r);
		}
	}
	if(l->key > root->key){
		int temp=root->key;
		root->key=l->key;
		l->key=temp;
		heapify(l);
	}
	return root;
}
int main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	Nodeptr root=NULL;
	for(int i=0;i<n;i++)
	{
		int m;
		printf("Enter key: ");
		scanf("%d",&m);
		insert_NormalBalanced(&root,m);
	}
	inorder(root);
	heapify(root);
	printf("\nAfter Heapify: \n");
	inorder(root);
}