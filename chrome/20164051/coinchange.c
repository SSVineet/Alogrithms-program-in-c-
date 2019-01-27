#include<stdio.h>
#include<string.h>
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
 
int coinchange(int note,int coin,int c[])
{
  int i,j;
  for(j=0;j<=coin;j++)
  {
    for(i=0;i<=note;i++)
   {
      dp[i][j]=0; 
   }
  }
  for(j=1;j<=coin;j++)
  {
  for(i=1;i<=note;i++)
  {
    if(j==1)
    {
    if(c[j]>i)
    dp[j][i]=dp[j-1][i];
    else
    dp[j][i]=max(dp[j-1][i],1+dp[j][i-c[j]]);
    }
    else if(j!=1)
    {
    if(c[j]>i)
    dp[j][i]=dp[j-1][i];
    else if(i>=c[j])
    dp[j][i]=min(dp[j-1][i],1+dp[j][i-c[j]]);
    }
  }
  }
  printf("\n");
  for(j=0;j<=coin;j++)
  {
    for(i=0;i<=note;i++)
   {
     printf("%d ",dp[j][i]); 
   }
   printf("\n");
  }
  return dp[coin][note];
}
void printcoins(int note,int coin,int c[])
{
  int j=coin;
  int i=note;
  while(i!=0&&j!=0)
  {
    if(dp[j][i]==dp[j-1][i])
    {
    j--;
    }
    else 
    {
    printf("%d ",c[j]);
    i=i-c[j];
    }
  }
}
int main(void)
{
 int note;
 printf("\n enter val of note");
 scanf("%d",&note);
 int c[100];
 int coin;
 printf("\n enter no of coins:");
 scanf("%d",&coin);
 printf("enter coins:");
 int i;
 for(i=1;i<=coin;i++)
 scanf("%d",&c[i]);
 int ans= coinchange(note,coin,c);
 printf("\nvalue of min coin needed is %d \n",ans);
 printf("\ncoins are:");
 printcoins(note,coin,c);
 printf("\n");
 return 0;
}
