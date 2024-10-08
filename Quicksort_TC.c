// Quick sort in C

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// main function
int main() {
  int data[100000];

  int n = 1000;
  srand(time(NULL));
  for(int i=0;i<n;i++)
  {
      data[i]=rand()%100;
  }

  clock_t start=clock();
  for(int i=0;i<10000;i++)
  {
      quickSort(data, 0, n - 1);
  }

  clock_t end=clock();
  double tn=(double)(end-start)/CLOCKS_PER_SEC;


  printf("\nTn=%f",tn);
}

//n=100 tn=0.208000
//n=200 tn=0.729000
//n=300 tn=1.551000
//n=500 tn=4.178000
//n=1000 tn=16.660000
