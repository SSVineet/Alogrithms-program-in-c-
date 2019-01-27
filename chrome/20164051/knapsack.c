#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
	return (a>b)? a : b ;
}
int knapsack(int wt[],int val[],int n, int maxW)
{
	int i,j;
	int dp[100][100];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=maxW;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
				continue;
			}
			if(wt[i-1] <= j)
				dp[i][j] = 	max( val[i-1] + dp[i-1][j-wt[i-1] ],  dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][maxW];
}
int main()
{
	int i,wt[1000],val[1000],n,res;
	printf("\n Enter the no. of items in the list :");
	scanf("%d", &n);
	printf("\n Enter the weight of the items and corrosponding value associated with it :");
	for(i=0;i<n;i++) {
		scanf("%d %d",&wt[i],&val[i]);
		}	
	int maxW;
	printf("\n Enter the Max. Weight that knapsack can hold :");
	scanf("%d", &maxW);
	printf("\n Max. Weight that knapsack can hold is %d :",knapsack(wt,val,n,maxW) );
	return 0;
}
