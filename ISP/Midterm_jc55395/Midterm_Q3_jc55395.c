/* Name: 		Justin Chao
 * UT EID: 		jc55395
 * Course: 		Introduction to Scientific Programming
 * Assignment: 	Midterm Question 3: Pascal's Triangle
 * References:  Rosetta Code: https://goo.gl/uy9Uza
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void triangle_mod2(int nRows) {
    int r, i, space;
    long *prevRow, val;

    if (nRows <= 0) return;
    prevRow = NULL;

    for (r=1; r<=nRows; r++) {
        long *currRow = malloc(r * sizeof(long));

        for (space=1; space <= nRows-i; space ++)
            printf (" ");

        for (i=0; i<r; i++) {

            val = i==0 || i==r-1 ? 1 : prevRow[i-1] + prevRow[i];
            currRow[i] = val;
            /*printf(" %ld", val);*/
            if (val%2 == 0)
                printf ("  ");
            else
                printf (" X");
        }
        printf("\n");
        free(prevRow);
        prevRow = currRow;
    }
    free(prevRow);
}

void triangle_usermod(int nRows, int N) {
    int r, i, space;
    long *prevRow, val;

    if (nRows <= 0) return;
    prevRow = NULL;

    for (r=1; r<=nRows; r++) {
        long *currRow = malloc(r * sizeof(long));

        for (space=1; space <= nRows-i; space ++)
            printf (" ");

        for (i=0; i<r; i++) {

            val = i==0 || i==r-1 ? 1 : prevRow[i-1] + prevRow[i];
            currRow[i] = val;
            if (val%N == 0)
                printf ("  ");
            else
                printf (" X");
        }
        printf("\n");
        free(prevRow);
        prevRow = currRow;
    }
    free(prevRow);
}

int main() {
    printf ("\n ========================= PROGRAM START ========================= \n");
    int N;

    printf ("Pascal's Triangle, where value = X if odd number and value = <space> if even number: \n");
    triangle_mod2(50);
    
    printf ("\n\nEnter an integer (N): \n");
    scanf ("%d", &N);
    printf ("Pascal's Triangle, where value = <space> if value%%%d = 0, else value = X: \n", N);
    triangle_usermod(50, N);

    printf ("\n ========================= PROGRAM END ========================= \n");
    return 0;
}
