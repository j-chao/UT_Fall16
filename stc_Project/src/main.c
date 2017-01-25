// main.c file for needleman_wunsch alignment program
#include "needleman_wunsch.h"
#include <stdio.h>
#include <stdlib.h>

// define scoring parameters
#define gap_penalty -5

#define A(i,j) score[(i) + (j)*n]

// variable declarations
int i, j, k, l, count = 0;
int score_current = 0, score_diagonal = 0, score_up = 0, score_left = 0;
int sizeAlign1 = 0;
int sizeAlign2 = 0;

// main.c takes two sequences as command line arguments
int main(int argc, char *argv[]) {

    // allocating plenty of memory to store each of the sequences 
    char *align1 = malloc(500*sizeof(char));  
    char *align2 = malloc(500*sizeof(char));

    if (argc != 3) {
        printf ("\nUsage: \n./Needleman_Wunsch <sequence1> <sequence2>\n\n");
        return 0;
    }

    printf("\n======================== PROGRAM START \n\n");

    int values[3];
    char seq1[m], seq2[n];

    // print sequences and user-defined lengths
    for (i=1; i<argc; i++)
        printf("Sequence %d: %s\n", i, argv[i]);  
    printf("\nSequence 1 and 2 lengths set to %d and %d in needleman_wunsch.h\n", m, n);

    // assign command line arguments to array of chars for each sequence
    for (i=0; i<=m; i++)
        seq1[i] = argv[1][i];
    for (i=0; i<=n; i++)
        seq2[i] = argv[2][i];

    // allocate memory for scoring matrix
    int *score = malloc ((m + 1)*(n + 1)*sizeof(int));

    // initially set all values to 0
    for (i=0; i< m; i++) 
        for (j=0; j< n; j++)
            A(i,j) = 0;
   
    // fill in first row
    for (k=0; k<n; k++) 
        A(0,k) = gap_penalty * k;

    // fill in first column
    for (l=0; l<m; l++)
        A(l,0) = gap_penalty * l;
    
    // fill in other values
    for (i=1; i<m; i++) {
        for (j=1; j<n; j++) {
            values[0] = A(i-1, j) + gap_penalty;
            values[1] = A(i, j-1) + gap_penalty;
            values[2] = A(i-1, j-1) + match_score (seq1[i-1], seq2[j-1]);
            A(i,j) = max_array(values, 3);
        }
    }

    // print Similarity Matrix
    printf ("\nSimilarity Matrix: ");
    printMatrix(score);

    // begin traceback
    i = m - 1;
    j = n - 1;

    while (i>0 && j>0) {
        score_current = A(i,j);
        score_diagonal = A((i-1),(j-1));
        score_up = A((i),(j-1));
        score_left = A((i-1),(j));

        if (score_current == score_diagonal + match_score(seq1[i-1], seq2[j-1])) {
            align1[count] = seq1[i-1];
            align2[count] = seq2[i-1];
            i --;
            j --;
            sizeAlign1 ++;
            sizeAlign2 ++;
            count ++;
        }
        else if (score_current == score_left + gap_penalty) {
            align1[count] = seq1[i-1];
            align2[count] = '-';
            i --;
            sizeAlign1 ++;
            sizeAlign2 ++; 
            count ++;
        }
        else if (score_current == score_up + gap_penalty) {
            align1[count] = '-';
            align2[count] = seq2[j-1];
            j --;
            sizeAlign1 ++;
            sizeAlign2 ++;
            count ++;
        }
    }
    
    // finish tracing up to top left cell
    while (i > 0) {
        align1[count] = seq1[i-1];
        align2[count] = '-';
        i --;
        sizeAlign1 ++;
        sizeAlign2 ++;
        count ++;
    }
    while (j > 0) {
        align1[count] = '-';
        align2[count] = seq2[j-1];
        j --;
        sizeAlign1 ++;
        sizeAlign2 ++;
        count ++;
    } 

    finalize (align1, align2, sizeAlign1, sizeAlign2);

    printf("\n========================= END PROGRAM \n");
    return 0;
}
