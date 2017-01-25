/* Name: Justin Chao
 *File: ICL3_jc55395.c
 * Calculate pi using Bailey-Borwein-Plouffe and Bellard's formulas. 
 * Compare the convergence rates of both algorithms.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// calculate PiA and error
void comp_PiA (int num_iter, double *PiA, double *err_PiA) {
        int i;
        double sum = 0;
        // calculate PiA and store iterations
        for (i=0; i<num_iter; i++) {   
                // cast int i to float n for calculations
                double n = i;
                sum   = 1/pow(16,n) * ( (4/(8*n+1)) 
                      - (2/(8*n+4)) - (1/(8*n+5)) 
                      - (1/(8*n+6)) );
                PiA[i] = sum + PiA[i-1];
        }
        // calculate error and store iterations
        for (i=1; i<num_iter; i++) {
                err_PiA[i-1] = 0.0;
                err_PiA[i-1] = PiA[i] - PiA[i-1];
        }
}

// calculate PiB and error
void comp_PiB (int num_iter, double *PiB, double *err_PiB) {
        int i;
        double sum = 0;
        // calculate PiB and store iterations
        for (i=0; i<num_iter; i++) {   
                // cast int i to float n for calculations
                double n = i;
                sum     = pow(-1,n)/pow(2,10*n) * 
                        (-(pow(2,5)/(4*n+1)) - (1/(4*n+3))
                        + (pow(2,8)/(10*n+1)) - (pow(2,6)/(10*n+3)) 
                        - (pow(2,2)/(10*n+5)) - (pow(2,2)/(10*n+7)) 
                        + (1/(10*n+9)) );
                PiB[i] = (sum + PiB[i-1]);
        }
        for (i=0; i<num_iter; i++) PiB[i] = PiB[i] * 1/pow(2,6);
        // calculate error and store iterations
        for (i=1; i<num_iter; i++) {
                err_PiB[i-1] = 0.0;
                err_PiB[i-1] = PiB[i] - PiB[i-1];
        }
}

// print arrays
void printAr (int num_iter, double *Ar) {
        int i;
        for (i=0; i<num_iter; i++) printf("\t%0.15f ", Ar[i]);
        printf("\n");
}

int main () {
        int num_iter, i;
        double *PiA     = (double *) malloc ((num_iter+1) * sizeof(double));
        double *PiB     = (double *) malloc ((num_iter+1) * sizeof(double));
        double *err_PiA = (double *) malloc ((num_iter+1) * sizeof(double));
        double *err_PiB = (double *) malloc ((num_iter+1) * sizeof(double));
        double *diffAB  = (double *) malloc ((num_iter+1) * sizeof(double));

        printf("Enter number of iterations: ");
        scanf("%d", &num_iter);
    
        printf ("\nBailey–Borwein–Plouffe formula:\n");
        comp_PiA (num_iter, PiA, err_PiA);
        printf("Pi \t = %0.15f \n", PiA[num_iter-1]);
        printf("error \t = %0.15f \n", err_PiA[num_iter-2]);
        printf("PiA array: ");   
        printAr(num_iter, PiA);
        printf("err_PiA array: ");   
        printAr(num_iter-1, err_PiA);

        printf ("\nBellard’s formula:\n");
        comp_PiB (num_iter, PiB, err_PiB);
        printf("Pi \t = %0.15f \n", PiB[num_iter-1]);
        printf("error \t = %0.15f \n", err_PiB[num_iter-2]);
        printf("PiB array: ");   
        printAr(num_iter, PiB);
        printf("err_PiB array: ");   
        printAr(num_iter-1, err_PiB);

        // calculate and print absolute value difference of PiA[i] - PiB[i]
        for (i=0; i<(num_iter); i++) diffAB[i] = fabs(PiA[i] - PiB[i]);

        printf ("\nDifference: %0.15f \n", diffAB[num_iter-1]);
        printf("diffAB array: ");
        printAr(num_iter, diffAB); 

        return 0;
}
