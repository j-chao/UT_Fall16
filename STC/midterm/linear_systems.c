/* Name:       Justin Chao
 * UT EID:     jc55395
 * Course:     Scientific and Technical Computing
 * Midterm:    Jacobi, Gauss-Seidel, and LU Factorization methods for solving
 *             Ax=b
 * References: Intel Developer Reference:  https://goo.gl/rCByls
 *             Dream in Code:              https://goo.gl/hMOrcK
 *             Planet Source Code:         https://goo.gl/mu5a5x
 *             Apple Accelerate-BLAS:      https://goo.gl/lyp81X
 */

#define min(x,y) (((x) < (y)) ? (x) : (y)) 
#define EPSILON 0.00001
#define MAXITER 10
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mkl.h"

int main()
{
    printf ("\n ========================== PROGRAM START ==========================\n\n");
    float *A, *x, *b, *actual_x, error = 1.0, normb, normGuess;
    int m, n, i, j, count = 1;
   
    // matrix size 
    printf ("Enter square matrix size (m): \n"); 
    scanf ("%d", &m);
    n = m;

    printf ("\n ...Initializing data for matrix A(%ix%i)\n\n", m, n);

    printf (" ...Allocating memory for matrices aligned on 64-byte boundary for better \n"
            " performance \n\n");

    A = (float *)mkl_malloc( m*n*sizeof( float ) , 64 );
    b = (float *)mkl_malloc( m*n*sizeof( float ) , 64 );
    actual_x = (float *)mkl_malloc( m*sizeof( float ) , 64 );
    x = (float *)mkl_malloc( m*sizeof( float ) , 64 );
    
    if (A == NULL || b == NULL || actual_x == NULL || x == NULL) {
        printf( "\n ERROR: Can't allocate memory for matrices. Aborting... \n\n");
        mkl_free(A);
        mkl_free(b);
        mkl_free(actual_x);
        mkl_free(x);
        return 1;
    }

    printf (" ...Intializing matrix A data (diagonally dominant) \n\n");
    for (i=0; i<(m*n); i++) {
        A[i] = (int)(rand() %5);
    }
    for (i=0; i<(m*n); i+=(m+1)) {
        A[i] = (int)(rand() %10000+8000);
    }

    printf (" Top left corner of matrix A: \n");
    for (i=0; i<min(m,6); i++) {
        for (j=0; j<min(n,6); j++) {
            printf ("%12.0f", A[j+i*m]);
      }
      printf ("\n");
    }
    
    printf ("\n ...Randomizing solution vector x \n");
    for (i=0; i<m; i++) {
        actual_x[i] = (int)(rand() %100);
    }
    
    printf ("\n First 6 values in solution vector x: \n");
    for (i=0; i<min(m,6); i++) {
        printf ("%12.0f", actual_x[i]);
    }

    printf ("\n\n ...Initializing vector b using CBLAS_SGEMV (b=A*x) \n");
    cblas_sgemv (CblasRowMajor, CblasNoTrans, m, n, 1, A, m, actual_x, 1, 0, b, 1);

    printf("\n First 6 values in vector b: \n\n");
    for (i=0; i<min(m,6); i++) {
        printf ("%12.0f", b[i]);
    }

    // calculate norm of vector b
    normb = cblas_snrm2 (n, b, 1);
    printf("\n\n Norm of vector b: %8.5f ", normb);

    printf ("\n\n ========================= JACOBI'S METHOD ========================= \n");
    clock_t begin_jacobi = clock();

    float *guess_x = (float *)mkl_malloc( m*sizeof( float ) , 64 );
    float *copy_c= (float *)mkl_malloc( m*sizeof( float ) , 64 );
    float *norm_vec = (float*)mkl_malloc( m*sizeof( float ) , 64 );

    for (i=0; i<m; i++) guess_x[i] = 1;

    printf("\n First 6 values in solution vector x: \n\n");
    printf(" Starting Guess: \n ");
    for (i=0; i<min(n,6); i++)  printf(" %7.5G  ", guess_x[i]);
    printf("\n");

    // do solve for x iteratively while error > EPSILON
    do { 
        for (i=0; i<n; i++) {
            copy_c[i] = b[i];
            for (j=0; j<n; j++) {
                if (i != j) {
                    copy_c[i] = copy_c[i] - A[i+j*m] * guess_x[j];
                }
            }
        }

        for(i=0; i<n; i++) {
            guess_x[i] = copy_c[i] / A[i+i*m];
        }

        printf("\n Iteration: %d \n", count);
        for (i=0; i<min(n,6); i++)  printf(" %8.5G  ", guess_x[i]);

        // calculate error using norm of vector guess_x
        for (i=0; i<n; i++) {
            norm_vec[i] = fabs(actual_x[i] - guess_x[i]);
        }
        // cblas_snrm2 computes the L2 norm (Euclidian length) of a vector (single precision)
        normGuess = cblas_snrm2 (n, norm_vec, 1);

        error =  normGuess / normb;
        printf (" ERROR = %10.5G \n", error);

        count ++;
    } while (error >= EPSILON && count <= MAXITER);

    mkl_free(copy_c);
    mkl_free(guess_x);

    clock_t end_jacobi = clock();
    double time_spent_jacobi = (double)(end_jacobi - begin_jacobi) / CLOCKS_PER_SEC;
    printf("\n Jacobi's Method CPU runtime = %f seconds. \n", time_spent_jacobi);


    printf ("\n ========================== GAUSS-SEIDEL ========================== \n");
    clock_t begin_gs = clock();
    count = 1;
    float *c= (float *)mkl_malloc( m*sizeof( float ) , 64 );
    for (i=0; i<m; i++) c[i] = 1;


    printf ("\n First 6 values in solution vector x: \n\n");
    printf(" Starting Guess: \n ");
    for (i=0; i<min(n,6); i++)  printf(" %7.5G  ", c[i]);
    printf("\n");

    // do solve for x iteratively while error > EPSILON
    do {
        for(i=0; i<n; i++) {
            c[i] = (b[i] / A[i+i*m]);
            for (j=0; j<n; j++) {
                if (j==i)
                    continue;
                c[i] = c[i] - ((A[i+j*m] / A[i+i*m]) * x[j]);
                x[i] = c[i];
            }
        }
        printf("\n Iteration: %d \n", count);
        for (i=0; i<min(n,6); i++)  printf(" %8.5G  ", c[i]);

        // calculate error using norm of vector c
        for (i=0; i<n; i++) {
            norm_vec[i] = fabs(actual_x[i] - c[i]);
        }

        // cblas_snrm2 computes the L2 norm (Euclidian length) of a vector (single precision)
        normGuess = cblas_snrm2 (n, norm_vec, 1);

        error =  normGuess / normb;
        printf (" ERROR = %10.5G \n", error);

        count ++;

    } while (error >= EPSILON && count <= MAXITER);

    mkl_free(c);
    mkl_free(norm_vec);

    clock_t end_gs = clock();
    double time_spent_gs = (double)(end_gs - begin_gs) / CLOCKS_PER_SEC;
    printf("\n Gauss-Seidel Method CPU runtime = %f seconds. \n", time_spent_gs);


    printf ("\n\n ========================= DIRECT SOLUTION ========================= \n");

    /* This method solves a linear system of equations Ax=b using
     * Intel(R) MKL LAPACK functions SGETRF and SGETRS,
     * where A is a matrix, x is a solution vector, and b is a vector.

     * SGETRF computes an LU factorization of a general m-by-n matrix A
     * using partial pivoting with row interchanges.
     * The factorization has the form
     *     A = P * L * U
     * where P is a permutation matrix, L is lower triangular with unit
     * diagonal elements (lower trapezoidal if m > n), and U is upper
     * triangular (upper trapezoidal if m < n).
     */

    clock_t begin_total = clock();
    clock_t begin_factor = clock();

    printf ("\n ...Factoring matrix A into L and U via SGETRF \n");
    int info;
    int *ipiv = (int*)mkl_malloc( m*sizeof( int ) , 64 );
    SGETRF(&m, &n, A, &m, ipiv, &info);

    printf ("\n Top left corner of matrix U: \n");
    for (i=0; i<min(m,6); i++) {
        for (j=0; j<min(n,6); j++) {
            printf ("%12.0f", A[i+j*m]);
      }
      printf ("\n");
    }
   
    if (info != 0){
        printf("\n ERROR: SGETRF unsuccessful, info != 0. Aborting... \n\n ");
        mkl_free(A);
        mkl_free(b);
        mkl_free(actual_x);
        mkl_free(x);
        mkl_free(ipiv);
        return 1;
    }

    clock_t end_factor = clock();
    double time_spent_factor = (double)(end_factor - begin_factor) / CLOCKS_PER_SEC;
    printf("\n\n Direct Method Factorization CPU runtime = %f seconds. \n", time_spent_factor);

    clock_t begin_direct = clock();
    printf ("\n\n ...Solving Ax=b via SGETRS \n");
    char trans = 'N';
    int nrhs = 1;
    SGETRS(&trans, &m, &nrhs, A, &m, ipiv, b, &n, &info);

    if (info != 0){
        printf("\n ERROR: SGETRS unsuccessful, info != 0. Aborting... \n\n ");
        mkl_free(A);
        mkl_free(b);
        mkl_free(actual_x);
        mkl_free(x);
        mkl_free(ipiv);
        return 1;
    }

    printf ("\n First 6 values in solution vector x: \n");
    for (i=0; i<min(m,6); i++) {
            printf (" %8.6G ", b[i]);
    }

    
    // calculate error using norm of vector b
    for (i=0; i<n; i++) {
        norm_vec[i] = fabs(actual_x[i] - b[i]);
    }
    normGuess = cblas_snrm2 (n, norm_vec, 1);

    error =  normGuess / normb;
    printf (" ERROR = %10.5G \n", error);


    clock_t end_direct = clock();
    double time_spent_direct = (double)(end_direct - begin_direct) / CLOCKS_PER_SEC;
    printf("\n\n Direct Method Solution CPU runtime = %f seconds. \n", time_spent_direct);
    
    clock_t end_total = clock();
    double time_spent_total = (double)(end_total - begin_total) / CLOCKS_PER_SEC;
    printf("\n\n Direct Method Total CPU runtime = %f seconds. \n", time_spent_total);

    printf ("\n\n ...Deallocating memory \n\n");
    mkl_free(A);
    mkl_free(b);
    mkl_free(actual_x);
    mkl_free(x);
    /* mkl_free(ipiv) results in error:
    * *** glibc detected *** ./a.out: corrupted double-linked list
    */

    printf (" Program completed. \n\n");
    return 0;
}
