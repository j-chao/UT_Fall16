// Justin Chao
// EID: jc55395
// add_vector.c adds finds the sum of the first 50 terms of the following arithmetic sequence: 
// 1, 3, 5, 7, 9...
  

// formula: Sn = n / 2 (2a + (n - 1) d)
// Sn = sum of first n terms
// n = number of terms
// a = first term of sequence
// d = common difference between terms (in this case, 2)

#include <stdio.h>
int main()
{
    //define n and read value from keyboard
    float n;
    printf("Enter number of terms (n) to add \n");
    scanf("%f" , &n);

    //define variables a and d.
    int a = 1;
    int d = 2;

    //define sumN to store results of calculation
    float sumN;

    sumN = n/2 * (2*a + (n - 1) * d);

    //print sumN
    printf("Sum = %f \n" , sumN);

    return 0;
}
