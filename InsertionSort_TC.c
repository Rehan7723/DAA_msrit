// Quick sort in C

#include <stdio.h>
#include<stdlib.h>
#include<time.h>


void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (j >=0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
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
      insertionSort(data, n);
  }

  clock_t end=clock();
  double tn=(double)(end-start)/CLOCKS_PER_SEC;


  printf("\nTn=%f",tn);
}

//n=100 tn=0.002
//n=200 tn=0.007
//n=300 tn=0.008
//n=500 tn=0.17
//n=1000 tn=0.34

