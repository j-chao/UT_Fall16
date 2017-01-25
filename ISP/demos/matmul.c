// Matrix Multiplication using functions and dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
// note the names of the matrices being passed to fcts.

void printMatrix(double **arrayA, int M, int N);
void matmul (double **matA, double **matB, int M, int N);
void allocArrayDouble (double **a, int M, int N);

int main() {
        int Rows, Cols;
        int i, j, count;
        double **myMatrixA, **myMatrixB;
        Rows = 2;
        Cols = 2;
        allocArrayDouble (myMatrixA, Rows, Cols);
        allocArrayDouble (myMatrixB, Rows, Cols);
        count = 1;
        for (i=0; i<Rows; i++){
                for (j=0; j<Cols; j++) {
                        myMatrixA[i][j] = count;
                        myMatrixB[i][j] = count;
                        count++;
                }
        }
        matmul (myMatrixA, myMatrixB, Rows, Cols);
        for (int i=0; i<Rows; i++) free (myMatrixA[i]);
        free (myMatrixA);

        for (int i=0; i<Rows; i++) free (myMatrixB[i]);
        free (myMatrixB);
        return 0;
}

void matmul (double **matA, double **matB, int M, int N) {
        int i, j, k, sum;
        double **myMatrixC = allocArrayDouble (M, N);
        // perform matrix multiply
        for (i=0; i<M; i++) {
                sum = 0;
                for (k=0; k<N; k++){
                        sum += matA[i][k] * matB[k][j];
                }
                myMatrixC[i][j] = sum;
        }
}

void printMatrix (double **arrayA, int M, int N){
        int i, j;
        printf ("Matrix C is: \n");
        for (i=0; i<M; i++){
                for (j=0; j<N; j++){
                        printf(" %lf ", arrayA[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}

void allocArrayDouble (double **a, int M, int N) {
        int i;
        a = malloc (M * sizeof(double *)); // check for NULL here
        for (i=0; i<M; i++) {
                a[i] = malloc (N * sizeof(double)); // check for Null here
        }
}
