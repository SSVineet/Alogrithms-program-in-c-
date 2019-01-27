#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void heapify(int arr[], int n, int i)
{
    int largest = i,tmp;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        tmp=arr[i];
        arr[i]= arr[largest];
        arr[largest]=tmp;
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    int i,tmp;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i=n-1; i>=0; i--)
    {
        tmp=arr[i];
        arr[i]= arr[0];
        arr[0]=tmp;        
        heapify(arr, i, 0);
    }
}

int main()
{
	clock_t start, end;
        double time1,time2,time3;
	int n,a[1000000+1],i;
	printf ( "# n best av. worst case\n" );
	for(n=0;n<=1000000;n+=100000)
	{
		start = clock();
        	srand(time(0));
        	for(i=0;i<=n;i++)
        	{
                	a[i]=rand();
        	}
		heapSort(a,n);
		end = clock();
    		time1 = ((double) (end - start)) / CLOCKS_PER_SEC;
		start = clock();
                for(i=0;i<n;i++)
                {
                        a[i]=i;
                }
                heapSort(a,n);
                end = clock();
                time2 = ((double) (end - start)) / CLOCKS_PER_SEC;
		start = clock();
                for(i=0;i<n;i++)
                {
                        a[i]=n-i;
                }
                heapSort(a,n);
                end = clock();
                time3 = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("%d %.3lf %.3lf %.3lf\n",n,time2,time1,time3);
	}
	return 0;
}
