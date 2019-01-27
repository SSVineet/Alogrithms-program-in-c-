#include<stdio.h>
#include<time.h>
int main()
{
  int i,j,k,n;
  scanf("%d",&n);
  int arr[n];
  for(i=0;i<n;i++)
  {
       scanf("%d",&arr[i]);
  }
   time_t t1=clock();
    for(i=1;i<n;i++)
  {
     k=arr[i];
     for(j=i-1;j>=0 && k<arr[j];j--)
            arr[j+1]=arr[j];
       arr[j+1]=k;
   }
   time_t t2=clock();
   double sec=(double)((t2-t1)/(CLOCKS_PER_SEC));
   printf("%lfsec",sec);
    for(i=0; i<n; i++)
          printf("%d\n",arr[i]);
    printf("\n");
}
  
