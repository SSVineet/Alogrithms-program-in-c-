#include<stdio.h>
int max(int a,int b)
{
	if(a>b) return a;
	return b;
}
int main()
{
	int n,i,j;
	printf("enter length of the rod\n");
	scanf("%d",&n);
	printf("enter values for diff lengths:\n");
	int arr[n+1],ar[n+1];
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<=n;i++) ar[i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			ar[i]=max(ar[i],ar[i-j]+arr[j]);
		}
	}
	printf("%d\n",ar[n]);
}
