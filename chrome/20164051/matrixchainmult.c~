#include<stdio.h>
#include<string.h>
#include<limits.h>
int print[100][100];
 int dp[100][100];
 int max(int a,int b)
 {
 if(a>b)
 return a;
 return b;
 }
 int min(int a,int b)
 {
   if(a<b) 
   return a;
   return b;
 }
 
int matchangemult(int n,int a[])
{
  int i,j;
  int l,k;
  for(i=n;i>=1;i--)
  {
  for(l=n;l>=1;l--)
  { 
      j=n-l+1;
      dp[i][j]=10000;
      for(k=i;k<j;k++)
       {
         if(i==j)
         dp[i][j]=0;
         else 
         dp[i][j]=min(dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j],dp[i][j]);
       }
  }
  }
  for(i=0;i<=n;i++)
  {
    for(j=0;j<n;j++)
       {
         printf("%d ",dp[i][j]);
       }
       printf("\n");
  }
   return dp[1][n];  
}  
int main(void)
{
int n;
 printf("\n enter no of matrix:");
 scanf("%d",&n);
 printf("enter matric order:");
 int a[100];
 int i;
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 int ans= matchangemult(n,a);
 printf("\n");
 printf(" min no. of mul op is %d\n",ans);
 return 0;
}
