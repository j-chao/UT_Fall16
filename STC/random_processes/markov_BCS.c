/* Name:       Justin Chao
 * UT EID:     jc55395
 * Course:     SDS 335
 * Assignment: markov_BCS.c predicts a BCS ranking for the big 12
 *             conference given this year’s team football record listed in
 *             matrix.txt
 * References: -
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mkl.h"
int i, j, k;

void printMatrix (double matrix[100]);
void printVector (double vector[10]);

int main() {
   printf ("\n ==================== PROGRAM START ====================\n");

   double *mat, *pVector, *sol, *sol2, *sol3, *sol4, *sol5, *sol6,
          *sol7, *sol8, *sol9, *sol10, *sol11, *sol12, *sol13,
          *sol14, *sol15, *sol16, *sol17, *sol18, *sol19, *sol20;

   // allocate memory for mat and pVector
   mat = (double *)malloc(100*sizeof(double*)); 
   pVector = (double *)malloc(10*sizeof(double*)); 
   sol = (double *)malloc(10*sizeof(double*)); 
   sol2 = (double *)malloc(10*sizeof(double*)); 
   sol3 = (double *)malloc(10*sizeof(double*)); 
   sol4 = (double *)malloc(10*sizeof(double*)); 
   sol5 = (double *)malloc(10*sizeof(double*)); 
   sol6 = (double *)malloc(10*sizeof(double*)); 
   sol7 = (double *)malloc(10*sizeof(double*)); 
   sol8 = (double *)malloc(10*sizeof(double*)); 
   sol9 = (double *)malloc(10*sizeof(double*)); 
   sol10 = (double *)malloc(10*sizeof(double*)); 
   sol11 = (double *)malloc(10*sizeof(double*)); 
   sol12 = (double *)malloc(10*sizeof(double*)); 
   sol13 = (double *)malloc(10*sizeof(double*)); 
   sol14 = (double *)malloc(10*sizeof(double*)); 
   sol15 = (double *)malloc(10*sizeof(double*)); 
   sol16 = (double *)malloc(10*sizeof(double*)); 
   sol17 = (double *)malloc(10*sizeof(double*)); 
   sol18 = (double *)malloc(10*sizeof(double*)); 
   sol19 = (double *)malloc(10*sizeof(double*)); 
   sol20 = (double *)malloc(10*sizeof(double*)); 

   // open and read stochastic Markov matrix from matrix.txt
   FILE *file;
   file = fopen("matrix.txt", "r");
   for(i = 0; i < 100; i++) {
       fscanf(file, "%lf", &mat[i]);
   }
   fclose(file);

   // print Markov matrix
   printf ("Markov Matrix: ");
   printMatrix(mat);

   // create random initial probability vector
   // RECALCULATE MARKOV MATRIX TO 4 DECIMAL PLACES AND CHECK ACCURACY
   printf ("\n...Randomizing initial probability vector");
   double sum = 0;
   for (i=0; i<10; i++) {
       pVector[i] = (double)(rand() %5);
       sum += pVector[i];
   }

   for (i=0; i<10; i++) {
       pVector[i] = pVector[i] / sum;
   }

   printVector(pVector);

   // multiply Markov matrix by initial probability vector
   printf ("\n\n...Multiplying Markov matrix by probability vector");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, pVector, 1, 0, sol, 1);
   printVector(sol);
   printf ("iter 1");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol, 1, 0, sol2, 1);
   printVector(sol2);
   printf ("iter 2");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol2, 1, 0, sol3, 1);
   printVector(sol3);
   printf ("iter 3");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol3, 1, 0, sol4, 1);
   printVector(sol4);
   printf ("iter 4");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol4, 1, 0, sol5, 1);
   printVector(sol5);
   printf ("iter 5");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol5, 1, 0, sol6, 1);
   printVector(sol6);
   printf ("iter 6");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol6, 1, 0, sol7, 1);
   printVector(sol7);
   printf ("iter 7");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol7, 1, 0, sol8, 1);
   printVector(sol8);
   printf ("iter 8");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol8, 1, 0, sol9, 1);
   printVector(sol9);
   printf ("iter 9");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol9, 1, 0, sol10, 1);
   printVector(sol10);
   printf ("iter 10");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol10, 1, 0, sol11, 1);
   printVector(sol11);
   printf ("iter 11");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol11, 1, 0, sol12, 1);
   printVector(sol12);
   printf ("iter 12");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol12, 1, 0, sol13, 1);
   printVector(sol13);
   printf ("iter 13");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol13, 1, 0, sol14, 1);
   printVector(sol14);
   printf ("iter 14");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol14, 1, 0, sol15, 1);
   printVector(sol15);
   printf ("iter 15");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol15, 1, 0, sol16, 1);
   printVector(sol16);
   printf ("iter 16");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol16, 1, 0, sol17, 1);
   printVector(sol17);
   printf ("iter 17");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol17, 1, 0, sol18, 1);
   printVector(sol18);
   printf ("iter 18");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol18, 1, 0, sol19, 1);
   printVector(sol19);
   printf ("iter 19");

   cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, sol19, 1, 0, sol20, 1);
   printVector(sol20);
   printf ("iter 20");

   // testing loop of cblas_dgemv
   // cblas_dgemv not working under loop...
   /*printf ("\n\n...testing loop of cblas_dgemv");*/
   /*for (k=0; k<20; k++) {*/
       /*cblas_dgemv (CblasRowMajor, CblasNoTrans, 10, 10, 1, mat, 10, pVector, 1, 0, sol, 1);*/
       /*printVector(sol);*/
       /*pVector = sol;*/
       /*printf ("iter %d", k+1);*/
   /*}*/

   printf ("\n\n ===================== END PROGRAM =====================\n");
   free (mat);
   free (pVector);
   free (sol);
   free (sol2);
   free (sol3);
   free (sol4);
   free (sol5);
   free (sol6);
   free (sol7);
   free (sol8);
   free (sol9);
   free (sol10);
   free (sol11);
   free (sol12);
   free (sol13);
   free (sol14);
   free (sol15);
   free (sol16);
   free (sol17);
   free (sol18);
   free (sol19);
   free (sol20);
   return 0;
}


void printMatrix (double matrix[100]) {
   printf ("\n");
   for (i=0; i<10; i++){
       for (j=0; j<10; j++) {
          printf ("%2.5f   ", matrix[j+i*3]);
       }
       printf ("\n");
   }
}

void printVector (double vector[10]) {
   printf ("\n");
   for (i=0; i<10; i++) {
       printf ("%2.5f   ", vector[i]);
   }
}
