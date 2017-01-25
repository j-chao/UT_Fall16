/* Name: 		Justin Chao
 * UT EID: 		jc55395
 * Course: 		Introduction to Scientific Programming
 * Assignment: 	Midterm Question 2: Arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float x;
float a[10], b[10];
float c[10][10], d[10][10];
int i, j;

// generate a random floating point number from min to max
float randfrom(float min, float max) {
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

// print array
void printArray(float array[10]) {
    for (i=0; i<10; i++) printf (" %5.3f  ", array[i]);
}

// print matrix
void printMatrix(float matrix[10][10]) {
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            printf(" %5.3f  ", matrix[i][j]);
        }
        printf("\n");
    }
}

// set array a equal to array b
void aTob (float a[10], float b[10]) {
    for (i=0; i<10; i++) a[i] = b[i];
}

// set array a elements equal to x
void aTox (float a[10], float x) {
    for (i=0; i<10; i++) a[i] = x;
}

// set array a equal to first row of matrix c
void aToc (float a[10], float c[10][10]) {
    for (i=0; i<10; i++) a[i] = c[0][i];
}

// set first 3 elements of array a equal to last 3 elements of matrix c
void aToLastc (float a[10], float c[10][10]) {
    for (i=0; i<3; i++) a[i] =c[9][7+i];
}

// set matrix c equal to matrix d
void cTod (float c[10][10], float d[10][10]) {
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            c[i][j] = d[i][j];
        }
    }
}

int main() {
	srand (time(NULL));
    printf ("\n ========================= PROGRAM START ========================= \n");
    // randomize x and arrays
    x = randfrom(0,10);
	for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            c[i][j] = randfrom(0, 10);
            d[i][j] = randfrom(0, 10);
        }
        a[i] = randfrom(0, 10);
        b[i] = randfrom(0, 10);
    }
    
    printf ("\n array a: \n");
    printArray(a);
    printf ("\n\n array b: \n");
    printArray(b);
    printf ("\n\n matrix c: \n");
    printMatrix(c);
    printf ("\n matrix d: \n");
    printMatrix(d);
    printf ("\n x = %5.3f", x);

    printf ("\n\n a after being set equal to array b: \n");
    aTob(a, b);
    printArray(a);

    printf ("\n\n a after elements set equal to x: \n");
    aTox(a, x);
    printArray(a);

    printf ("\n\n a after being set equal to first row of matrix c: \n");
    aToc(a, c);
    printArray(a);

    printf ("\n\n a after first 3 elements set equal to last 3 elements of matrix c: \n");
    aToLastc(a, c);
    printArray(a);

    printf ("\n\n c after being set equal to matrix d: \n");
    cTod(c, d);
    printMatrix(c);

    printf ("\n\n ========================= PROGRAM END ========================= \n");

	return 0;
}
