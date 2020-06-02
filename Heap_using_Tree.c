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
void insert_Heap(Nodeptr* root,int key)
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
		if(trav->key < key)
		{
			int temp=trav->key;
			trav->key=key;
			key=temp;
		}
		if(count_nodes(trav->left)==count_nodes(trav->right))
			trav=trav->left;
		else if((count_nodes(trav->left)-1)%2 != 0)
			trav=trav->left;
		else
			trav=trav->right;
	}if(trav->key < key)
	{
		int temp=trav->key;
		trav->key=key;
		key=temp;
	}
	temp->key=key;
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
		insert_Heap(&root,m);
	}
	inorder(root);
}