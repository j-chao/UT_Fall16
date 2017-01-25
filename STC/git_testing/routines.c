#include <math.h>
void isqrt(float *a, int n){
        int i;
//                      Vector inverse square
//                      Someone advised to 
//                      make two separate loops.

        // combined both loops
        for (i=0; i<n; i++){

            a[i] = sqrt(a[i]);
            a[i] = 1.0e0/a[i];
        }

//        for (i=0; i<n; i++) a[i] = 1.0e0/a[i];
}
