/* Name: Justin Chao
 * Course: SDS 332
 * Date Created: 9/20/2016
 * Program: returns n-th number of Fibonacci Sequence per user passed argument.
 * */

#include <stdio.h>

int main() {

    // initialize array and variables
    long fib[40], i, n;
    
    // read user input
    printf("Enter a number: ");
    scanf("%ld", &n);

    // check array size constraints
    if (n > 40){
        printf("Number must be < 40\n");
    }
    // compute Fibonacci Sequence
    else
    {
        for(i=0; i < n; i++)
        {
            // set first two terms of sequence
            if (i < 2)
                fib[i] = 1;
            // compute the rest of the sequence
            else
                fib[i] = fib[i-1] + fib[i-2];
            // print results
            printf("fib[%ld]: %ld \n", i, fib[i]);
        }
    }
    return 0;
}
