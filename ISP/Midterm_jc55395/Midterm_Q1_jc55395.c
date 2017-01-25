/* Name: 		Justin Chao
 * UT EID: 		jc55395
 * Course: 		Introduction to Scientific Programming
 * Assignment: 	Midterm Question 1: Control Structures
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// initiate 10x10 double dimension matrix A
double A[10][10], A_t[10][10], col_sum[10], row_sum[10], sum, diag_sum, average;
int i, j;


// generate a random floating point number from min to max
double randfrom(double min, double max) {
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

// fill matrix with random numbers (0-10)
void fillMatrix (double matrix[10][10]) {
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            matrix[i][j] = randfrom(0.0, 10.0);
        }
    }
}

// print matrix
void printMatrix(double matrix[10][10]) {
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            printf(" %5.3f  ", matrix[i][j]);
        }
        printf("\n");
    }
}

// sum rows of matrix into array row_sum
void sumRows(double matrix[10][10]) {
    printf ("\n Sum of Rows: \n");
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            sum += matrix[i][j];
        }
        row_sum[i] = sum;
        sum = 0;
    }
    for (i=0; i<10; i++) printf(" %5.3f  ", row_sum[i]);
}

// sum columns of matrix into array col_sum
void sumCols(double matrix[10][10]) {
    printf ("\n\n Sum of Columns: \n");
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            col_sum[j] += matrix[i][j];
        }
    }
    for (i=0; i<10; i++) printf(" %5.3f  ", col_sum[i]);
}

// calculates trace (sum of diagonal of matrix)
void sumDiag (double matrix[10][10]) {
    printf ("\n\n Sum of Diagonal: \n");
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            if (i==j){
                sum += matrix[i][j];
            }
        }
    }
    printf(" %5.3f  ", sum);
}

// transpose the matrix and print
void transMatrix (double matrix[10][10]) {
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            A_t[i][j] = A[j][i];
        }
    }
    printMatrix(A_t);
}

// calculate average and replace matrix accordingly, then print
void replaceMatrix (double matrix[10][10]) {
    sum = 0;
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            sum += A[i][j];
        }
    }
    average = sum/100;
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            if (A[i][j] < average) A[i][j] = 0;
            if (A[i][j] > average) A[i][j] = 1;
        }
    }
    printMatrix(A);
}


int main() {
	srand (time(NULL));
    printf ("\n ========================= PROGRAM START ========================= \n");
    fillMatrix(A);
    printf("\n Matrix A \n");
    printMatrix(A);
    sumRows(A);
    sumCols(A);
    sumDiag(A);
    printf("\n\n Transposed Matrix A_t \n");
    transMatrix(A);
    printf("\n\n Replaced Matrix A \n");
    replaceMatrix(A);
    printf ("\n ========================= PROGRAM END ========================= \n");
    return 0;
}
