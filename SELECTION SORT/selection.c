#include<stdio.h>
#include<time.h>
int main()
{
 int n,i,j,small,temp;
 scanf("%d",&n);
 int a[n];
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 time_t t1=clock(); 
 for(i=0;i<n;i++)
 {
   small=i;
   temp=a[small];
   for(j=i+1;j<n;j++)
   {  if(a[small]>a[j])
       small=j;
   }
  a[i]=a[small];
  a[small]=temp;
 }
 time_t t2=clock();
 double sec=(double)((t2-t1)/(CLOCKS_PER_SEC));
 printf("%lf\n",sec);
/* for(i=0;i<n;i++)
 printf("%d ",a[i]);  */
 return 0;
}
