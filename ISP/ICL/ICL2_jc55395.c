/* Justin Chao
 * Introduction to Scientific Programming, In Class Lab 2
 * Journey of a Pointer
 * ICL2_jc55395.c
 */

#include <stdio.h>

int main(){

        // declare a one-dimensional, integer array named a that can hold 10 elements
        // declare an integer pointer
        int a[10], i, *ptr;

        // initialize the array elements to the square of their index value
        for (i=0; i<10; i++) a[i] = i*i;

        // let the pointer point to the fourth element in the array
        ptr = &a[3];

        // print to trace the journey of the pointer
        printf( "*ptr     = %d \n", *ptr);
        printf( "*ptr+1   = %d \n", *ptr+1);
        printf( "*(ptr+1) = %d \n", *(ptr+1));
        printf( "*ptr++   = %d \n", *ptr++);
        printf( "*(ptr++) = %d \n", *(ptr++));
        printf( "*++ptr   = %d \n", *++ptr);
        printf( "*(++ptr) = %d \n", *(++ptr));
        printf( "*ptr     = %d \n", *ptr);

        return 0;
}
