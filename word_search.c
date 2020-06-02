#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
int main()
{
	int m,n;
	printf("Enter the size of matrix: ");
	scanf("%d %d",&m,&n);
	char matrix[m][n],str[50];
	printf("Enter the matrix:  ");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf(" %c",&matrix[i][j]);
		}
	}
	printf("Enter the string: ");
	scanf(" %s",str);
	int len=strlen(str);
	int found=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]==str[0])
			{
				//row search
				if((j+len)<=n)
				{
					int k=0;
					while(str[k]!='\0' && str[k]==matrix[i][j+k])
					{
						k++;
					}
					if(k==len)
					{
						found=1;
						printf("\nFound HORIZONTALLY at Row: %d, Column: %d",i+1,j+1);
					}
				}
				//column search
				if((i+len)<=m)
				{
					int k=0;
					while(str[k]!='\0' && str[k]==matrix[i+k][j])
					{
						k++;
					}
					if(k==len)
					{
						found=1;
						printf("\nFound VERTICALLY at Row: %d, Column: %d",i+1,j+1);
					}
				}
				//diagonal down -x -y
				if((j+len)<=n && (i+len)<=m)
				{
					int k=0;
					while(str[k]!='\0' && str[k]==matrix[i+k][j+k])
					{
						k++;
					}
					if(k==len)
					{
						found=1;
						printf("\nFound DIAGONALLY DOWN at Row: %d, Column: %d",i+1,j+1);
					}
				}
				//diagonal up -x y
				if((j-len)>=-1 && (i-len)>=-1)
				{
					int k=0;
					while(str[k]!='\0' && str[k]==matrix[i-k][j-k])
					{
						k++;
					}
					if(k==len)
					{
						found=1;
						printf("\nFound DIAGONALLY UP at Row: %d, Column: %d",i+1,j+1);
					}
				}
				//diagonal up x y
				if((j+len)<=n && (i-len)>=-1)
				{
					int k=0;
					while(str[k]!='\0' && str[k]==matrix[i-k][j+k])
					{
						k++;
					}
					if(k==len)
					{
						found=1;
						printf("\nFound DIAGONALLY UP at Row: %d, Column: %d",i+1,j+1);
					}
				}
				//diagonal down x -y
				if((j-len)>=-1 && (i+len)<=m)
				{
					int k=0;
					while(str[k]!='\0' && str[k]==matrix[i+k][j-k])
					{
						k++;
					}
					if(k==len)
					{
						found=1;
						printf("\nFound DIAGONALLY DOWN at Row: %d, Column: %d",i+1,j+1);
					}
				}
			}
		}
	}
	if(found==0)
		printf("\nNot Found");
}