#include <stdio.h>
#include <stdlib.h>

int coinChange(int arr[],int n,int amt){
	int i,take,notTake,j,v[amt+1][n];
	for(i=0;i<n;i++){
		v[0][i]=1;
	}
	for(i=1;i<=amt;i++){
		for(j=0;j<n;j++){
			//not take
			if(j>=1)
			notTake=v[i][j-1];
			else
			notTake=0;
			//take
			if(i-arr[j]>=0)
			take=v[i-arr[j]][j];
			else
			take=0;
			v[i][j]=take+notTake;
			}
	}
	return v[amt][n-1];
}

int main(){
	int n,i,amt;
	printf("enter amount whose change we want\n");
	scanf("%d",&amt);
	printf("enter types of coins\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter coin values\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("number of ways that we can get a change is %d\n",coinChange(arr,n,amt));
	return 0;
}

