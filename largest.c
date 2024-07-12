#include<stdio.h>
#include<time.h>
void largest(int arr[],int n)
{
    clock_t start=clock();
    int max=0;
    for(int j=0;j<=1000000;j++)
    {
        for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    }
    printf("The max value of the array is:%d\n",max);
    clock_t end=clock();
    double res=(double)((end-start)/CLOCKS_PER_SEC);
    printf("T(n)=%f",res);
}
void main()
{
    int arr[100000];
    int n=20000;
    for(int i=0;i<n;i++)
    {
        arr[i]=rand(1,10000);
    }
    largest(arr,n);
}