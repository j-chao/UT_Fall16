/* Name: Justin Chao
 * Program: matrix by matrix operation with reuse
 * */

#include <stdio.h>

// initialize matrices and variables
float C[2048][2048], A[2048][2048], B[2048][2048], sum;
int i, j, k;

int main(){
    for (i=0; i<2048; i++){
        for (j=0; j<2048; j++){
            sum = 0;
            for (k=0; k<2048; k++){
                /*A[i][j] = B[i][j] = 1.0;*/
                sum = sum + A[i][k]*B[j][k];
            }
            C[i][j] = sum;
        }
    }
    return 0;
}
