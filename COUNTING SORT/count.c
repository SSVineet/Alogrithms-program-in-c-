#include<stdio.h>
#include<time.h>
#define RANGE 10000000
void count(int a[],int n)
{
    int b[n+5],c[RANGE+1],i;
    for(i=0;i<=RANGE;i++) c[i]=0;
    for(i = 1; i<=n; i++)
        c[a[i]]++;
    for (i = 1; i <= RANGE; ++i)
        c[i] += c[i-1];
    for (i = n; i>=1; i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    //b is output array
}
int main()
{
	clock_t start, end;
        double time1,time2,time3;
	int n,a[RANGE+1],i;
	printf ( "# n best av. worst case\n" );
	for(n=0;n<=RANGE;n+=1000000)
	{
		start = clock();
        	srand(time(0));
        	for(i=0;i<=n;i++)
        	{
                	a[i]=rand()/10000;
			if(a[i]<0) a[i]=-a[i];
        	}
		count(a,n);
		end = clock();
     		time1 = ((double) (end - start)) / CLOCKS_PER_SEC;
		start = clock();
                for(i=0;i<n;i++)
                {
                        a[i]=i;
                }
                count(a,n);
                end = clock();
                time2 = ((double) (end - start)) / CLOCKS_PER_SEC;
		start = clock();
                for(i=0;i<n;i++)
                {
                        a[i]=n-i;
                }
                count(a,n);
                end = clock();
                time3 = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("%d %.3lf %.3lf %.3lf\n",n,time2,time1,time3);
	}
	return 0;
}
