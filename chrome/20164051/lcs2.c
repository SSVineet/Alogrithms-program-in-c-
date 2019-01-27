/*
	NUMBER OF ALL POSSIBLE LCS
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int L[1005][1005];  // DP for LCS
int D[1005][1005];   // DP for number of possible LCS
int max(int a, int b)
{
	return (a>b) ? a : b ;
}
int LCS(char X[],char Y[])
{
         int m = strlen(X);
         int n = strlen(Y);
         int i,j;
         for (i=0;i<=m;i++)
         {
             for (j=0;j<=n;j++)
             {
                 if (i==0 || j==0)
                    L[i][j]=0;
                 else
                 {
                     if (X[i-1] == Y[j-1])
                        L[i][j] = L[i-1][j-1] + 1;
                     else
                         L[i][j]= max (L[i][j-1] , L[i-1][j] );
                 }
             }
         }
         return (L[m][n]);
}     
int NLCS(char X[],char Y[])
{
        int m = strlen(X);
        int n = strlen(Y);
        int i,j;
        for (i=0;i<=m;i++)
        {
            for (j=0;j<=n;j++)
            {
                 if (i==0 || j==0)
                    D[i][j] = 1;
                 else
                 {
                     D[i][j]=0;
                     if (X[i-1] == Y[j-1])
                     {
                        D[i][j] = D[i-1][j-1];
                     }
                     else
                     {
                         if (L[i-1][j] == L[i][j]) 
                            D[i][j] = D[i][j] + D[i-1][j] ;
                         if (L[i][j-1] == L[i][j]) 
                            D[i][j] = D[i][j] + D[i][j-1] ;
                         if (L[i-1][j-1] == L[i][j])         
                         {
                            D[i][j] = D[i][j] + D[i-1][j-1];      // now add the case when same LCS is found     
                         } 
                     }
                 }
            }
         }
         return (D[m][n]);
    }
int main()
{
	char a[100],b[100];
	printf("\n Enter the first string :");
	scanf("%s", a);
	printf("\n Enter the 2nd string :");
	scanf("%s", b);
	int l1,l2;
	l1 = strlen(a);
	l2 = strlen(b); 
	int res = LCS(a,b);
	printf("\n Length of the LCS of the given two strings is :%d\n", res);
	int dis = NLCS(a,b);
	printf("No. of possible LCS of given strings are :%d\n", dis);
	return 0;
}
