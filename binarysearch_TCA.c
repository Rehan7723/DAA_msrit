#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int search(int a, int left, int right, int key)
{
    while(left<right)
    {
        int mid=(right+left)/2;
        if(mid==key) 
        {
            return 1;
        }
        else if(key<mid)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return 0;
}

void main()
{
    int a[10000];
    int key=110;
    srand(time(NULL));
    int n=4000;
    for(int i=0;i<n;i++)
    {
        a[i]= rand()%100;
    }

    time_t start= clock();
    for(int i=0;i<10000;i++)
    {
        search(a,0,n-1,key);
    }
    time_t end= clock();
    double tn=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Time complexity= %f ", tn);

}

// n	tn
// 100	0.000104
// 500	0.00014
// 1000	0.000165
// 1500	0.000166
// 2000	0.000175
// 4000	0.000188
