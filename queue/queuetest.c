#include "queueinclude.h"
#include <stdio.h>

int main() {
        queue *start = NULL;
    while(1) {
        printf("1. add\n2.remove\n3.print\n");
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("enter an integer: ");
            int val;
            scanf("%d", &val);
            if (start == NULL)
                start = newQueue(val);
            else
                qadd(val, start);
            break;
        case 2:
            start = qdelete(start);
            break;
        case 3:
            qprint(start);
            break;
        default:
            printf("invalid response.\n");
            break;
        }
    }
}
