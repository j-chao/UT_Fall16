// needleman_wunsch.c file for needleman_wunsch alignment program
#include "needleman_wunsch.h"
#include <stdio.h>
#include <stdlib.h>

// define scoring parameters
#define gap_penalty -5
#define matchScore  10
#define mismatch -5

int match_score(char a, char b) {
    int m_score, i, a_num, b_num;
    if (a == b)
      return matchScore;
    else if (a == '-' || b == '-') 
      return gap_penalty;
    else // there is a mismatch
      return mismatch;
}

int max_array (int  a[], int num_elements) {
    int i, max=-5000;
    for (i=0; i<num_elements; i++)
        if (a[i]>max) max = a[i];
    return max;
}

void printMatrix (int matrix[m*n]) {
    int i, j; 
    printf ("\n"); 
    for (i=0; i<m; i++){
        for (j=0; j<n; j++)
            printf ("%5.1d  ", matrix[i+j*m]);
        printf ("\n");
   }
}

void reverseSeq(char arr[], int start, int end) {
    int temp;
    while (start < end) {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start ++;
        end --;
    }   
}    

void finalize (char align1[], char align2[], int sizeAlign1, int sizeAlign2) {
    int i;
    // reverse sequences
    reverseSeq (align1, 0, sizeAlign1);
    reverseSeq (align2, 0, sizeAlign2);
    
    char *symbol = malloc(500*sizeof(char));

    int scoreNum = 0, count = 1;

    for (i=1; i<=sizeAlign1; i++){
        // if two AAs are the same, output the letter
        if (align1[i] == align2[i]) {
            symbol[count] = align1[i];
            scoreNum = scoreNum + match_score(align1[i], align2[i]);
            count ++;
        }
        // if they are not identical and none of them is gap
        else if (align1[i] != align2[i] && align1[i] != '-' && align2[i] != '-') {
            scoreNum = scoreNum + match_score(align1[i], align2[i]);
            symbol[count] = ' ';
            count ++;
        }
        // if one of them is a gap, output a space
        else if (align1[i] == '-' || align2[i] == '-') {
            symbol[count] = ' ';
            scoreNum = scoreNum + gap_penalty;
            count ++;
        }
    }

    printf ("\nAlignment Results:\n\n");
    for (i=0; i<=sizeAlign1; i++) printf ("%c ", align1[i]);

    printf ("\t\tSequence 1\n\n");
    for (i=0; i<=count; i++) printf ("%c ", symbol[i]);

    printf ("\tMatch\n\n");
    for (i=0; i<=sizeAlign2; i++) printf ("%c ", align2[i]);

    printf ("\t\tSequence 2\n");

    printf ("\n Score = %d\n", scoreNum);
}
