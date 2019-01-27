#include<time.h>
#include<bits/stdc++.h>
using namespace std;
double arr[100001];
int n;
void bucket()
{
	vector <double> b[100001];
 	int i;
	int j;
	int index=0;
	for(i=0;i<n;i++)
	{
		int bi=n*arr[i];// any kind of hash function
		b[bi].push_back(arr[i]);
	}
	for(i=0;i<n;i++)
		sort(b[i].begin(),b[i].end());
	for(i=0;i<n;i++)
	{
		for(j=0;j<b[i].size();j++)
	{
		arr[index++]=b[i][j];

	}
	}
}
int main()
{
	clock_t start, end;
        double time1,time2,time3;
	int i;
	printf ( "# n best av. worst case\n" );
	for(n=0;n<=1000000;n+=100000)
	{
		start = clock();
        	srand(time(0));
        	for(i=0;i<=n;i++)
        	{
                	arr[i]=rand();
        	}
		bucket();
		end = clock();
    		time1 = ((double) (end - start)) / CLOCKS_PER_SEC;
		start = clock();
                for(i=0,j=0;i<n;i++)
                {
                        arr[i]=i/n;
                }
                bucket();
                end = clock();
                time2 = ((double) (end - start)) / CLOCKS_PER_SEC;
		start = clock();
                for(i=0;i<n;i++)
                {
                        arr[i]=1/n;
                }
                bucket();
                end = clock();
                time3 = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("%d %.3lf %.3lf %.3lf\n",n,time2,time1,time3);
	}
	return 0;
}