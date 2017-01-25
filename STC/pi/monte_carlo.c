/* Name:        Justin Chao
 * UT EID:      jc55395
 * Course:      Scientific and Technical Computing
 * Assignment:  Monte Carlo calculation of Pi
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#define SEED 35791246
#define PI (3.141592653589793)

double parallelPi(const int numTotalSamples);
double samplesInsideCircle (const int sampleSize);

int main() {
    double pi, time_spent;
    
    printf("======================= PROGRAM START =======================\n");
    printf("Monte Carlo calculation of Pi.\n\n");

    clock_t begin1 = clock();
    pi = parallelPi(10000);
    clock_t end1 = clock();
    time_spent = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf ("Sample Size: 10000 \t\t Pi = %f \n", pi);
    printf ("error: %f \n", fabs(PI-pi));
    printf ("run time: %f sec\n\n", time_spent);

    clock_t begin2 = clock();
    pi = parallelPi(1000000);
    clock_t end2 = clock();
    time_spent = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf ("Sample Size: 1000000 \t\t Pi = %f \n", pi);
    printf ("error: %f \n", fabs(PI-pi));
    printf ("run time: %f sec\n\n", time_spent);

    clock_t begin3 = clock();
    pi = parallelPi(1000000000);
    clock_t end3 = clock();
    time_spent = (double)(end3 - begin3) / CLOCKS_PER_SEC;
    printf ("Sample Size: 1000000000 \t Pi = %f \n", pi);
    printf ("error: %f \n", fabs(PI-pi));
    printf ("run time: %f sec\n", time_spent);

    printf("\n======================= END PROGRAM =======================\n");
    return 0;
}

double parallelPi(const int numTotalSamples) {
    double approxPi;
   	int numChunks = 8, counter, i;
   	int chunk = numTotalSamples / numChunks;

   	for (i=0; i<numChunks; i++) {
		counter += samplesInsideCircle(chunk);
   	}

   	return approxPi = 4.0 * counter / numTotalSamples;
}

double samplesInsideCircle (const int sampleSize) {
    int counter = 0, s;
    double x, y;

    #pragma omp parallel 
    for (s = 0; s <= sampleSize; s++) {
        x = (double) rand()/RAND_MAX;
        y = (double) rand()/RAND_MAX;

        if (x*x + y*y < 1) {
            counter++; 
        }
    }
    return counter;
}
