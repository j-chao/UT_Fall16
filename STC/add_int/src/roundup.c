#include "roundup.h"  /* Include the header (not strictly necessary here) */

int round_em_up(int x, int arr[])    /* Function definition */
{
   int i, sum=0;
   for (i=0; i<x; i++)
   {
     sum = sum + arr[i];
   }
   return(sum);    
}
