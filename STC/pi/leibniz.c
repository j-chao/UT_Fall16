/* Name:        Justin Chao
 * UT EID:      jc55395
 * Course:      Scientific and Technical Computing
 * Assignment:  Numerical calculation of Pi through the Leibniz's series
 * References:  Code Project: https://goo.gl/IY2w5R
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI (3.141592653589793)

double calc_pi (double size);

int main() {
    double pi, time_spent;

    printf("======================= PROGRAM START =======================\n");
    printf("Numerical calculation of Pi through Leibniz's series.\n\n");
   
    clock_t begin1 = clock();
    pi = calc_pi(10000);
    clock_t end1 = clock();
    time_spent = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf ("Sample Size: 10000 \t\t Pi = %f \n", pi);
    printf ("error: %f \n", fabs(PI-pi));
    printf ("run time: %f sec\n\n", time_spent);

    clock_t begin2 = clock();
    pi = calc_pi(1000000);
    clock_t end2 = clock();
    time_spent = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf ("Sample Size: 1000000 \t\t Pi = %f \n", pi);
    printf ("error: %f \n", fabs(PI-pi));
    printf ("run time: %f sec\n\n", time_spent);

    clock_t begin3 = clock();
    pi = calc_pi(1000000000);
    clock_t end3 = clock();
    time_spent = (double)(end3 - begin3) / CLOCKS_PER_SEC;
    printf ("Sample Size: 1000000000 \t Pi = %f \n", pi);
    printf ("error: %f \n", fabs(PI-pi));
    printf ("run time: %f sec\n", time_spent);

    printf("\n======================= END PROGRAM =======================\n");
    return 0;
}


double calc_pi (double size) {
    double i, s=1, pi=0;

    #pragma omp parallel
    for(i=1; i<=(size*2); i+=2) {
        pi = pi + s*(4/i);
        s = -s;
    }
    return pi;
}
