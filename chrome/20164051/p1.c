#include<stdio.h>
void knapsac(int W, int val[], int w[], int n)
{
	int i,j,dp[n+1][W+1],check[n+1][W+1],max;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<W+1;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
				check[i][j]=0;
			}
			else if(w[i]>j)
			{
				dp[i][j]=0;
				check[i][j]=0;
			}
			else
			{
				max=dp[i-1][j];
				if(dp[i-1][j]<(val[i]+dp[i-1][j-w[i]]))
				{
					max=val[i]+dp[i-1][j-w[i]];
				}
				dp[i][j]=max;
				if((val[i]+dp[i-1][j-w[i]])>=dp[i][j])
				{
					check[i][j]=1;
				}
				else
					check[i][j]=0;
			}
		}
	}
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<W+1;j++)
			{
				printf("%d",dp[i][j]);
			}
			printf("\n");
	}
}
				
int main()
{
	int val[100],w[100],W,i,n;
	printf("enter total no. of items\n");
	scanf("%d",&n);
	printf("enter space seperated weights\n");
	for(i=1;i<n+1;i++)
	{
		scanf("%d", &w[i]);
	}
	printf("enter space seperated price\n");
	for(i=1;i<n+1;i++)
	{
		scanf("%d", &val[i]);
	}
	printf("enter capacity\n"); 
	scanf("%d",&W);
	knapsac(W,val,w,n);
	return 0;
}
	
