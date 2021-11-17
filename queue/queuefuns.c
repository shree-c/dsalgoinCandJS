#include <stdio.h>
#include <stdlib.h>
#include "./queueinclude.h"

queue *newQueue(int data) {
    queue *hold = newNode(data, NULL);
    return hold;
}

void qadd(int data, queue *start) {
    queue *hold = start;
    if (start == NULL) {
        hold = newNode(data, NULL);
    } else {
        while(hold->next != NULL) {
            printf("%d....\n", hold->data);
            hold = hold->next;
        }
        hold->next = newNode(data, NULL);
    }
}

queue *qdelete(queue *start) {
    if (start == NULL) {
        fprintf(stderr, "Queue is empty!\n");
        return start;
    }
    printf("deleted: %d\n", start->data);
    queue *nextaddress = start->next;
    free(start);
    return nextaddress;
}

void qprint(queue *start) {
    printf("-->start of queue\n");
    printLlist(start);
    printf("-->end of queue\n");
}
