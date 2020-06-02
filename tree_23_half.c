#include<stdio.h>
#include<stdlib.h>
typedef struct Node* Nodeptr;
typedef struct Node{
	int k1,k2,fill;
	Nodeptr l,m,r,parent;
}Node;
Nodeptr insert_key(Nodeptr trav, int key)
{
	if(trav->k1==key)
		return trav;
	else if(trav->k1 > key)
	{
		trav->k2=trav->k1;
		trav->k1=key;
	}else
		trav->k2=key;
	trav->fill=1;
	return trav;
}
Nodeptr newNode(int key)
{
	Nodeptr temp=malloc(sizeof(Node));
	temp->k1=key;
	temp->fill=0;
	temp->l=NULL;
	temp->m=NULL;
	temp->r=NULL;
	temp->parent=NULL;
	return temp;	
}
void insert(Nodeptr* root,int key)
{
	if(*Nodeptr==NULL)
	{
		Nodeptr temp=newNode(key);
		*root=temp;
		return;
	}
	Nodeptr trav=*root;
	while(trav->l || trav->r || trav->m)
	{
		if(key<k1)
			trav=trav->l;
		else if(key>k2)
			trav=trav->r;
		else
			trav=trav->m;
	}
	if(trav->fill==0)
	{
		trav=insert_key(trav,key);
		return;
	}else{
		if(trav->k1==key||trav->k2==key)
			return;
		int flag=0;
		while(flag==0)
		{
			int il=0,ir=0,im=0;
			Nodeptr par=trav->parent;
			if(par->l==trav)
			{
				il=1;
				im=ir=0;
			}else if(par->m==trav)
			{
				im=1;
				il=ir=0;
			}else{
				ir=1;
				il=im=0;
			}
			if(par==NULL)

			else{
				int s,m,b;
				s=(trav->k1 > trav->k2)?(trav->k2>key)?key:trav->k2:(trav->k1 > key)? key:trav->k1;
				b=(trav->k1 < trav->k2)?(trav->k2 < key)?key:trav->k2:(trav->k1 < key)? key:trav->k1;
				s=(trav->k1 > trav->k2)?(trav->k2>key)?trav->k2:key:(trav->k1 > key)? trav->k1:key;
				if(par->fill==0)
				{
					par=insert_key(par,m);
					Nodeptr left=newNode(s);
					left->parent=par;
					Nodeptr right=newNode(b);
					right->parent=par;
					if(im==1)
					{
						par->m=left;
						par->r=right;
					}else if()
				}
			}
		}
	}
}
int main()
{
	Nodeptr root=NULL;
	int m,n;
	do{
		printf("Enter \n1)Insert\n2)View\n0)Exit");
		scanf("%d",&n);
		switch(n)
		{

		}
	}
}