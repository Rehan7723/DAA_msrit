#include <stdio.h>
#include<time.h>

// function to display the matrix
void display(int result[][10], int row, int column) {

   printf("\nOutput Matrix:\n");
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("%d  ", result[i][j]);
         if (j == column - 1)
            printf("\n");
      }
   }
}

// function to get matrix elements entered by the user
void getMatrixElements(int matrix[][10], int row, int column) {

  // printf("\nEnter elements: \n");

   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         matrix[i][j]=rand(1,99);
      }
   }
  // display(matrix,row,column);
}

// function to multiply two matrices
void multiplyMatrices(int first[][10],
                      int second[][10],
                      int result[][10],
                      int r1, int c1, int r2, int c2) {

   // Initializing elements of matrix mult to 0.
   // for (int i = 0; i < r1; ++i) {
   //    for (int j = 0; j < c2; ++j) {
   //    }
   // } initialize it in the calculation loop itself
   clock_t start=clock();
   // Multiplying first and second matrices and storing it in result

   for(int z=0;z<=100000;z++)
   {
    for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         result[i][j] = 0;
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}
clock_t end=clock();
double res=(double)(end-start)/CLOCKS_PER_SEC;
printf("Time complexity=%f\n",res);
 }



int main() {
   int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2;
   r1=r2=6;
   c1=c2=6;

   // get elements of the first matrix
   getMatrixElements(first, r1, c1);

   // get elements of the second matrix
   getMatrixElements(second, r2, c2);

   // multiply two matrices.
   multiplyMatrices(first, second, result, r1, c1, r2, c2);

   // display the result
   //display(result, r1, c2);

   return 0;
}



/*n	tn
100	0.25027
200	0.556028
300	0.866297
500	1.489939
1000	3.115656
5000	17.583127*/

