// needleman_wunsch.h header file for needleman_wunsch alignment program

#ifndef needleman_wunch_h   // Include guard
#define needleman_wunch_h

#define m 20    // m = length of Sequence 1
#define n 20    // n = length of Sequence 2

int match_score(char a, char b);
int max_array (int a[], int num_elements);
void printMatrix (int matrix[m*n]);
void reverseSeq (char arr[], int start, int end);
void finalize (char align1[], char align2[], int sizeAlign1, int sizeAlign2);

#endif
