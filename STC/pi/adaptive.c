/* Name:        Justin Chao
 * UT EID:      jc55395
 * Course:      Scientific and Technical Computing
 * Assignment:  Adaptive integration calculation of Pi
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>
#define PI (3.141592653589793)

double calc_pi (int size);

int main(int argc,char **arg) {
	double pi, time_spent;

    printf("======================= PROGRAM START =======================\n");
    printf("Adaptive integration calculation of Pi.\n\n");

    clock_t begin1 = clock();
    pi = calc_pi (10000);
    clock_t end1 = clock();
    time_spent = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf ("Sample Size: 10000 \t\t Pi = %f \n", pi);
    printf ("error: %f \n", fabs(PI-pi));
    printf ("run time: %f sec\n\n", time_spent);

    clock_t begin2 = clock();
    pi = calc_pi (1000000);
    clock_t end2 = clock();
    time_spent = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf ("Sample Size: 1000000 \t\t Pi = %f \n", pi);
    printf ("error: %f \n", fabs(PI-pi));
    printf ("run time: %f sec\n\n", time_spent);

    clock_t begin3 = clock();
    pi = calc_pi (1000000000);
    clock_t end3 = clock();
    time_spent = (double)(end3 - begin3) / CLOCKS_PER_SEC;
    printf ("Sample Size: 1000000000 \t Pi = %f \n", pi);
    printf ("error: %f \n", fabs(PI-pi));
    printf ("run time: %f sec\n", time_spent);

    printf("\n======================= END PROGRAM =======================\n");
	return 0;
}

double calc_pi (int size) {
    int i, j;
    double quarterpi = 0., h = 1./size, pi;

    /*#pragma omp parallel*/
    for (i=0; i<size; i++) {
        double x = i*h, x2 = (i+1)*h, 
               y = sqrt(1-x*x), 
               y2 = sqrt(1-x2*x2), 
               slope = (y-y2)/h;

        if (slope>15) slope = 15;

        int samples = 1+(int)slope;
            
        /*#pragma omp parallel*/
        for (j=0; j<samples; j++) {
            double hs = h/samples, 
                   xs = x+ j*hs, 
                   ys = sqrt(1-xs*xs); 
            quarterpi += hs*ys;
        } 
    }
    pi = 4*quarterpi;
    return pi;
}
