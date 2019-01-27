#include<stdio.h>
int arr[20],n,ar[20][20];
int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}
int matmul(int i,int j)
{
	int k;
	if(i+1>=j) 
	return 0;
	if(ar[i][j]!=0) 
	return ar[i][j];
	int ans=100000000;
	for(k=i+1;k<j;k++)
	{
		ans=min(ans,arr[k]*arr[i]*arr[j]+matmul(i,k)+matmul(k,j));
	}
	ar[i][j]=ans;
	return ans;
}
int main()
{
	int i,j,a;
	printf("enter no. of matrices:");
	scanf("%d",&n);
	printf("enter the matrix:\n");
	for(i=0;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
			ar[i][j]=0;
	}
	a=matmul(0,n);
	printf("%d\n",a);
	return 0;
}
