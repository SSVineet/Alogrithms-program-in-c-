#include<stdio.h>
#include<limits.h>
 
int mco(int arr[], int n)
{
    int v[n][n];
    int i,j,k,l,q;
     for (i=1; i<n; i++)
        v[i][i] = 0;

    for (l=2;l<n;l++)
    {
        for (i=1;i<n-l+1;i++)
        {
            j = i+l-1;
            v[i][j]=99999
            
            ;
            for (k=i;k<=j-1;k++)
            {
                q = v[i][k] + v[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if (q < v[i][j])
                    v[i][j] = q;
            }
        }
    }
    return v[1][n-1];
}

int main()
{
    int n,i;
    printf("enter length of matrix chain\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter array for matrix chain\n");
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    }
    printf("minimum number of operations are %d\n",mco(arr,n));
    return 0;
}
