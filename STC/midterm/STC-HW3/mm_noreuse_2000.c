/* Name: Justin Chao
 * Program: matrix by matrix operation with noreuse
 * */

#include <stdio.h>

// initialize matrices and variables
float C[2000][2000], A[2000][2000], B[2000][2000];
int i, j, k;

int main(){
    for (i=0; i<2000; i++){
        for (j=0; j<2000; j++){
            C[i][j] = 0;
            for (k=0; k<2000; k++){
                /*A[i][j] = B[i][j] = 1.0;*/
                C[i][j] = C[i][j] + A[i][k] * B[j][k];
            }
        }
    }
    return 0;
}
