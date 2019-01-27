#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int a[100][100];
int x[100];
bool is_safe(int row,int col)
{
   int q;
   for(q=1;q<=row-1;q++)
   {
   if(x[q]==col)
   return 0;
   }
   for(q=1;q<=row-1;q++)
   {
   if(x[q]-row==x[q]-col)
   return 0;
   }
   return 1;
}
bool solvequeenproblem(int row,int n)
{
   int sol;
   int col;
   if(row>n)
   return 1;//means checked.
   for(col=1;col<=n;col++)
   {
     if(is_safe(row,col))
     {
      x[row]=col;
      sol=solvequeenproblem(row+1,n);
      if(sol)
      return sol;
     }
   }
   return 0;
}
int main(void)
{
  int n,i,j;
  printf("enter no of queen:");
  scanf("%d",&n);
  int solution[n+1][n+1];
  for(i=1;i<=n;i++)
  {
  for(j=0;j<=n;j++)
  {
   a[i][j]=0;
  }
  }
  solvequeenproblem(1,n);
  for(i=1;i<=n;i++)
  { 
  printf("%d   ",x[i]);
  }
  printf("\n\n");
  for(i=1;i<=n;i++)
  {
  for(j=1;j<=n;j++)
  {
    if(j==x[i])
    solution[i][j]=1;
    else
    solution[i][j]=0;   
  }
  }
  for(i=1;i<=n;i++)
  {
  for(j=1;j<=n;j++)
  {
    printf("%d  ",solution[i][j]);   
  }
   printf("\n");
  }
  return 0; 
}
