
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int lArr[n1], rArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        lArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (lArr[i] <= rArr[j]) {
            arr[k] = lArr[i];
            i++;
        }
        else {
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of lArr[], if any
    while (i < n1) {
        arr[k] = lArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rArr[], if any
    while (j < n2) {
        arr[k] = rArr[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left-right]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[100000];
    int n=5000;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    clock_t start=clock();

    for(int i=0;i<100000;i++)
    {
        mergeSort(arr, 0, n - 1);
    }

    clock_t end=clock();

    double tn=(double)(end-start)/CLOCKS_PER_SEC;

    printf("Time complexity= %f ", tn);
    return 0;
}
