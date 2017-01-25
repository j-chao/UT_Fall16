/* Name:       Justin Chao
 * UT EID:     jc55395
 * Couse:      SDS 335
 * Assignment: monte_carlo_pi.c computes Pi using Monte Carlo methods
 * Reference:  Dartmouth College 
 *             http://www.dartmouth.edu/~rc/classes/soft_dev/C_simple_ex.html
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

int main() {
   printf ("\n ==================== PROGRAM START ====================\n\n");

   int num = 1000000, i, count = 0;
   double x, y, z, pi;
  
   /* initialize random numbers */
   srand(SEED);
   count=0;

   for (i=0; i<num; i++) {
      x = (double) rand()/RAND_MAX;
      y = (double) rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
   }

   pi = (double) count/num*4;


   printf(" Number of trials  = %d \n Estimate of Pi    = %g \n", num, pi);

   printf ("\n ===================== END PROGRAM =====================\n");
   return 0;
}

