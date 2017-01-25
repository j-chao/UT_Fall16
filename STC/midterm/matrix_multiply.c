/* Name: Justin Chao
 * Course: Scientific and Technical Computing
 * Assignment: Midterm Question 1. Multiply two matricies using sgemm
 * References: https://software.intel.com/en-us/node/520775
 */


#define min(x,y) (((x) < (y)) ? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mkl.h"

int main()
{
    clock_t begin = clock();

    float *A, *B, *C;
    int m, n, k, kk, i, j;
    float alpha, beta;

    printf ("\n This program computes real matrix C=alpha*A*B+beta*C using \n"
            " Intel(R) MKL function sgemm, where A, B, and C are matrices and \n"
            " alpha and beta are float precision scalars\n\n");

    // matrix sizes
    printf (" Enter matrix A size (m x n): \n ");
    scanf ("%d %d", &m, &k);
    printf ("\n Enter matrix B size (m x n): \n ");
    scanf ("%d %d", &kk, &n);

    if (k != kk) {
        printf(" \n ERROR: Number of columns on matrix A must equal number of rows on matrix B.\n"
               " Aborting... \n\n");
        return 1;
    }

    printf ("\n ...Initializing data for matrix multiplication C=A*B for matrix \n"
            " A(%ix%i) and matrix B(%ix%i)\n\n", m, k, k, n);
    alpha = 1.0; beta = 0.0;

    printf (" ...Allocating memory for matrices aligned on 64-byte boundary for better \n"
            " performance \n\n");
    A = (float *)mkl_malloc( m*k*sizeof( float ), 64 );
    B = (float *)mkl_malloc( k*n*sizeof( float ), 64 );
    C = (float *)mkl_malloc( m*n*sizeof( float ), 64 );
    if (A == NULL || B == NULL || C == NULL) {
      printf( "\n ERROR: Can't allocate memory for matrices. Aborting... \n\n");
      mkl_free(A);
      mkl_free(B);
      mkl_free(C);
      return 1;
    }

    printf (" ...Intializing matrix data \n\n");
    for (i = 0; i < (m*k); i++) {
        A[i] = (int)(rand() %2000);
    }

    for (i = 0; i < (k*n); i++) {
        B[i] = (int)(rand() %2000);
    }

    for (i = 0; i < (m*n); i++) {
        C[i] = 0.0;
    }

    printf (" ...Computing matrix product using Intel(R) MKL sgemm function via CBLAS interface \n\n");
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                m, n, k, alpha, A, k, B, n, beta, C, n);

    printf ("\n ...Computations completed.\n\n");

    printf (" Top left corner of matrix A: \n");
    for (i=0; i<min(m,6); i++) {
      for (j=0; j<min(k,6); j++) {
        printf ("%12.0f", A[j+i*k]);
      }
      printf ("\n");
    }

    printf ("\n Top left corner of matrix B: \n");
    for (i=0; i<min(k,6); i++) {
      for (j=0; j<min(n,6); j++) {
        printf ("%12.0f", B[j+i*n]);
      }
      printf ("\n");
    }
    
    printf ("\n Top left corner of matrix C: \n");
    for (i=0; i<min(m,6); i++) {
      for (j=0; j<min(n,6); j++) {
        printf ("%12.5G", C[j+i*n]);
      }
      printf ("\n");
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n CBLAS_SGEMM CPU runtime = %f seconds. \n", time_spent);

    printf ("\n ...Deallocating memory \n\n");
    mkl_free(A);
    mkl_free(B);
    mkl_free(C);

    printf (" ...Program completed. \n\n");
    return 0;
}
