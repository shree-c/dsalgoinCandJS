#include <stdio.h>
#include <stdlib.h>
#include "./llinclude.h"
llnode *newNode(int data, llnode *next) {
    llnode *hold = (llnode *) malloc(sizeof(llnode));
    hold->data = data;
    hold->next = next;
    return hold;
}

void printLlist(llnode *start) {
    llnode *hold = start;
    while (hold != NULL) {
        printf("--> %d\n", hold->data);
        hold = hold->next;
    }
}