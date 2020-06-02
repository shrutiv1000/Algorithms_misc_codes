#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node* Nodeptr;
typedef struct Node{
	int data;
	Nodeptr left,right;
} Node;
int len=0;
void insertrecur(Nodeptr* root, int data)
{
	if(*root == NULL)
	{
		Nodeptr temp= (Nodeptr)malloc(sizeof(Node));
		temp->data=data;
		temp->left=temp->right=NULL;
		*root=temp;
		return;
	}
	printf("\nInsert to the left or right of %d:  ", (*root)->data);
	char str[10];
	scanf(" %s", str);
	if(strcmp(str,"left")==0)
		insertrecur(&((*root)->left),data);
	else
		insertrecur(&((*root)->right),data);
}
void inorder(Nodeptr root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}
int max(int a,int b)
{
	return (a>b)? a:b ;
}
int height(Nodeptr root)
{
	if(root==NULL)
		return 0;
	return (1+max(height(root->left),height(root->right)));
}
int int_path_length(Nodeptr root,int k)
{
	if(root==NULL)
		return len;
	else
		len+=k;
	int_path_length(root->left,k+1);
	int_path_length(root->right,k+1);
	return len;
}
int ext_path_length(Nodeptr root,int k)
{
	if(root==NULL){
		len+=k;
		return len;
	}
	else{	
	ext_path_length(root->left,k+1);
	ext_path_length(root->right,k+1);
	return len;}
}
int main()
{
	int n,m,p;
	Nodeptr root =NULL;
	do{
		printf("\nEnter \n1)Insert Recursively\n2)Print Inorder\n3)Internal Path Length\n0)Exit\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1: printf("Enter data: ");
			scanf("%d", &m);
			insertrecur(&root,m);
			break;
			case 2: inorder(root);
			break;
			case 3: printf("Internal Path length: %d",int_path_length(root,0));
			len=0;
			printf("\nExternal Path length: %d",ext_path_length(root,0));
			len=0;
			break;
		}
	}while(n!=0);
	return 0;
}