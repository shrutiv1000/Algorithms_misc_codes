#include<stdio.h>
#include<math.h>

int assign(int a[100][100],int n)
{
int p[n],fix[n];
int sum=TMP_MAX,sumtemp,temp;
for(int i=0;i<n;i++)
p[i]=i;

for (int j = 1; j <= n; j++)
{
for (int i = 0; i < n-1; i++)
{
            temp = p[i];
            p[i] = p[i+1];
            p[i+1] = temp;
           
       sumtemp=0;
       for(int k=0;k<n;k++)
        sumtemp+=a[k][p[k]];
       if(sum>sumtemp)
       {
           sum=sumtemp;
for(int k=0;k<n;k++)
fix[k]=p[k];
       }
}
}
printf("Person:\t");
for(int i=0;i<n;i++)
printf("%d\t",i+1);
printf("\nJob:\t");
for(int i=0;i<n;i++)
printf("%d\t",fix[i]+1);
printf("\nSum = %d",sum);

}

int main()
{
int a[100][100],n;
printf("Enter no. of jobs: ");
scanf("%d",&n);
printf("Enter value of person i and job j\n");
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
{
printf("%d & %d: ",i+1,j+1);
scanf("%d",&a[i][j]);
}
assign(a,n);

}