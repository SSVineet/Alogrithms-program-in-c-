#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
return a>b?a:b;
}

int rodCutting(int arr[],int n){
	int i,j,m,v[n+1];
	v[0]=0;
	for(i=1;i<=n;i++){
		 m=-1;
		for(j=1;j<=i;j++){
			m=max(m,arr[j]+v[i-j]);
		}
		v[i]=m;
	}
	return v[n];
}

int main(){
	int n,i;
	printf("enter rod length\n");
	scanf("%d",&n);
	int arr[n+1];
	printf("enter price array for each length\n");
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	int ans=rodCutting(arr,n);
	printf("Max price after cutting rod optimally is %d\n",ans);
	return 0;
}
