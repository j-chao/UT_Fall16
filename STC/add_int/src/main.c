#include <stdio.h>
#include "roundup.h" 

int main(int argc, char** argv) {

        // create integer list
        int Integer_List[4] =   {1,2,3,4};

        // call round_em_up function
        int result = round_em_up( 4, Integer_List);

        // print list of integers
        printf("List of integers to be added: ");
        int i;
        for (i=0; i<4; i++){
                printf("%d ", Integer_List[i]);
        }
        // print result
        printf("\nSum of list is %d.\n", result);

        return 0;
}
