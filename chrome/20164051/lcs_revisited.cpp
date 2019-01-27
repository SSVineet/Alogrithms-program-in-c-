    #include<iostream>
    using namespace std;
    int L[1005][1005];
    int D[1005][1005];
    int LCS(string X,string Y)
    {
         int m = X.length();
         int n=Y.length();
         
         int i,j;
         for (i=0;i<=m;i++)
         {
             for (j=0;j<=n;j++)
             {
                 if (i==0 || j==0)
                    L[i][j]=0;
                 else
                 {
                     if (X[i-1]==Y[j-1])
                        L[i][j]=L[i-1][j-1]+1;
                     else
                         L[i][j]=max(L[i][j-1],L[i-1][j]);
                 }
             }
         }
         return (L[m][n]);
    }
     
    int NLCS(string X,string Y)
    {
        int m = X.length();
        int n=Y.length();
        int i,j;
        for (i=0;i<=m;i++)
        {
            for (j=0;j<=n;j++)
            {
                 if (i==0 || j==0)
                    D[i][j]=1;
                 else
                 {
                     D[i][j]=0;
                     if (X[i-1]==Y[j-1])
                     {
                        D[i][j]=D[i-1][j-1];
                     }
                     else
                     {
                         if (L[i-1][j]==L[i][j]) 
                            D[i][j]=(D[i][j]+D[i-1][j])%23102009;
                         if (L[i][j-1]==L[i][j]) 
                            D[i][j]=(D[i][j]+D[i][j-1])%23102009;
                         if (L[i-1][j-1]==L[i][j]) 
                         {
                            if (D[i][j]<D[i-1][j-1])
                               D[i][j]+=23102009;
                            D[i][j]=(D[i][j]-D[i-1][j-1]);
                         }
                     }
                 }
            }
         }
         return (D[m][n]);
    }
     
    int main()
    {
        string X,Y;
        int t,A,B;
        scanf("%d",&t);
        while (t--)
        {
              cin>>X>>Y;
              A=LCS(X,Y);
              B=NLCS(X,Y);
              printf("%d %d\n",A,B);
        }
    } 
