#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int a[100000];
    int n=1000;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    clock_t start=clock();
    for(int k=0;k<100000;k++)
    {
        for(int i=0;i<n-1;i++)
        {
            int min=i;
            for(int j=i+1;j<n;j++)
            {
                if(a[j]<a[min])
                min=j;
            }
            int temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
        
    }
    clock_t end=clock();
       double tn=(double)(end-start)/CLOCKS_PER_SEC;

    printf("Time complexity= %f ", tn);

}


// n	tn
// 100	0.322278
// 200	1.132756
// 300	2.38591
// 500	6.284805
// 1000	24.054437
