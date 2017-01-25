// sort_potatoes.c
// sorts a sack of potatoes given user provided list of potato lengths

#include <stdio.h>
 
int main()
{
  int n, array[1000], c, d, t;

  // prompt user for number of potatoes 
  printf("Enter number of potatoes\n");
  scanf("%d", &n);

  // prompt user for lengths of potatoes 
  printf("Enter %d integers as potato lengths (in inches)\n", n);

  // scan potato lengths into an array 
  for (c = 0; c < n; c++) 
  {
    scanf("%d", &array[c]);
  }
    
  // Insertion Sort
  // iterate through the array 
  for (c = 1 ; c <= n - 1; c++) 
  {
    d = c;
 
    // swap array elements if element is larger than the previous element in the array 
    while ( d > 0 && array[d] > array[d-1]) 
    {
      t          = array[d];
      array[d]   = array[d-1];
      array[d-1] = t;
 
      d--;
    }
  }
 
  printf("Sorted list of potatoes in descending order of length in inches:\n");
 
  for (c = 0; c <= n - 1; c++) {
    printf("%d\n", array[c]);
  }
 
  return 0;
}
