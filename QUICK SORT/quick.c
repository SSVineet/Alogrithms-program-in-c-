#include<stdio.h>
#include<time.h>
int flag;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot;
    if(flag==1) swap(&arr[(low+high)/2],&arr[high]);
    pivot= arr[high];
    int i = (low - 1),j; 
    for ( j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
             i++;
             swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
    }
        
void quicksort(int arr[], int l, int r)
{
     if (l < r)
     {
          int pi = partition(arr, l, r);                                                               
          quicksort(arr, l, pi - 1);
          quicksort(arr, pi + 1, r);
     }
}
int main()
{
	clock_t start, end;
        double time1,time2,time3;
	int n,a[100000+1],i;
	printf ( "# n best av. worst case\n" );
	for(n=0;n<=100000;n+=10000)
	{
		start = clock();
        	srand(time(0));
        	for(i=0;i<=n;i++)
        	{
                	a[i]=rand();
        	}
		flag=0;  quicksort(a,0,n-1);
		end = clock();
     		time1 = ((double) (end - start)) / CLOCKS_PER_SEC;
		start = clock();
                for(i=0;i<n;i++)
                {
                        a[i]=i;
                }
                flag=1; quicksort(a,0,n-1);
                end = clock();
                time2 = ((double) (end - start)) / CLOCKS_PER_SEC;
		start = clock();
                for(i=0;i<n;i++)
                {
                        a[i]=n-i;
                }
                flag=0; quicksort(a,0,n-1);
                end = clock();
                time3 = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("%d %.3lf %.3lf %.3lf\n",n,time2,time1,time3);
	}
	return 0;
}
