#include<stdio.h>
#include<time.h>
int main()
{
   int i,j,temp,n;
   scanf("%d\n",&n);
   int a[n];
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   time_t t1=clock();
   for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
    { if(a[j]<a[j-1])
      { temp=a[j];
         a[j]=a[j-1];
          a[j-1]=temp;
      }
    }
   time_t t2=clock();
   double sec=(double)((t2-t1)/(CLOCKS_PER_SEC));
   printf("%lfsec\n",sec);
   for(i=0;i<n;i++)
    printf("%d ",a[i]);
   return 0;
}

   
      

