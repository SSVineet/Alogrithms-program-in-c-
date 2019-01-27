#include<stdio.h>
 
int count( int S[], int m, int n )
{
    int i, j, x, y;
 
 
    int table[n+1][m];
    
 
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            
            y = (j >= 1)? table[i][j-1]: 0;
 
            
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}
 

int main()
{
    int arr[100],i,n,m;
    printf("\n Enter the number of denominations\n");
    scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&arr[i]);
	}
    printf("\n Enter the amount to be changed\n");
    scanf("%d",&n);
    printf(" %d ", count(arr, m, n));
    return 0;
}
