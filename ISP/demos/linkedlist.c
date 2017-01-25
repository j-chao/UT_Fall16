// File: linkedlist.c
// Demonstration of linked list.



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *Next;
} Node;

int main () {
    Node* head = NULL;
    Node* tail = NULL;
    Node* cur  = NULL;

    int i;
    for (i=0; i<100; i++) {
        cur = (Node*)malloc(sizeof(Node));
        cur->val = 3*i;
        cur->Next = NULL;

        if (head == NULL) 
            head = cur;
        tail = cur; 
    }

    cur = head;
    while (cur != NULL)
    {
        printf("Memory Address: %p, Val: %d, Next = %p\n", cur, cur->val, cur->Next);
        cur = cur->Next;
    }    
}
