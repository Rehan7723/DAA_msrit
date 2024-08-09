#include <stdio.h>
#include <time.h>
int fact(int n)
{
    if(n==0) return 1;
    return n*fact(n-1);
}

void main()
{
    int n=200;
    int res;
    clock_t start= clock();
    for(int i=0;i<100000;i++)
    {
        res=fact(n);
    }
    clock_t end=clock();
    printf("%d",res);
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("T(n)=%f",time);
}
