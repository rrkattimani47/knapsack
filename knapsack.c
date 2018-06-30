#include<stdio.h>
#define MAX 200
int V[MAX][MAX]={0};
int res[200]={0};
int count=0;

int max(int a,int b)
{
	return (a>b)?a:b;

}

int knapsack(int w, int wt[], int val[], int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0 || j==0)
			{
				V[i][j]=0;
			}
			else if(wt[i-1<=j])
			{
				V[i][j]=max(val[i-1]+V[i-1][j-wt[i-1]],V[i-1][j]);
			}
			else
			{
				V[i][j]=V[i-1][j];
			}
		}
		int k,m;
		for(k=0;k<=n;k++)
		{
			for(m=0;m<=w;m++)
			{
				printf("%d",V[k][m]);
			}
			printf("\n");
		}
		printf("\n");
	}
	i=n;
	i=w;
	while(i>0 && j>0)
	{
		if(V[i][j]!=V[i-1][j])
		{
			res[count++]=1;
			j=j-wt[i-1];
			i--;

		}

else
	i--;

	}
	return V[n][w];
}
 int main()
{
	int i, n,w, optsoln;
	int val[20],wt[20];
	printf("Enter the number of items:\n");
	scanf("%d",&n);

	printf("Enter the weights:\n");
	for(i=0;i<n;i++)
		scanf("%d",&wt[i]);

	printf("Enter the values:\n");
	for(i=0;i<n;i++)
		scanf("%d",&val[i]);

	printf("Enter the knapsack capacity:\n");
	scanf("%d",&w);

	optsoln=knapsack(w,wt,val,n);

	printf("The optimal solution is:%d",optsoln);

	printf("\nThe optimal subsets\n");
	printf("Items included in knapsack are:");
	for(i=count-1;i>=0;i--)
		printf("\t%d",res[i]);
	printf("\n");
}