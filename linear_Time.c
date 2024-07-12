#include <stdio.h>
#include <time.h>

void linear(int arr[], int n, int key) {
    int flag = 0;
    clock_t start = clock();
    
    for (int i = 0; i <= 100000; i++) { 
        for (int j = 0; j < n; j++) {
            if (arr[j] == key) { 
                printf("found\n");
                flag = 1;
            }
        }
    }
    if (flag == 0)
        printf("Not found\n");
    clock_t stop = clock();
    double runTime = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\nTime taken=%f", runTime);
}

void main() {
    int arr[10] = {1, 5, 7, 2, 8, 1, 9, 1, 0, 3}; 
    int n = 9;
    int key = 99;
    linear(arr, n, key);
    //printf("Hello");
}

