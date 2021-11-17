#include "../stack.h"
void move(int i, stack *start, stack *end, stack *hold)
{
    if (i == 1)
    {
        printf("Move disk %d from %s tower to %s tower.\n", i, start->name, end->name);
        int tmp = pop(start);
        push(tmp, end);
        printf("tower A: ");
        printWhole(start);
        printf("tower B: ");
        printWhole(hold);
        printf("tower C: ");
        printWhole(end);
        return;
    }
    move(i - 1, start, hold, end);
    printf("Move disk %d from %s tower to %s tower.\n", i, start->name, end->name);
    int tmp = pop(start);
    push(tmp, end);
    printf("tower A: ");
    printWhole(start);
    printf("tower B: ");
    printWhole(hold);
    printf("tower C: ");
    printWhole(end);
    move(i - 1, hold, end, start);
}
int main()
{
    stack *A = newStack();
    A->name = "A";
    stack *B = newStack();
    B->name = "B";
    stack *C = newStack();
    C->name = "C";
    printf("**************Tower of hanoi************\n");
    printf("Enter the number of disks you want on first tower: ");
    int no_of_disks;
    scanf("%d", &no_of_disks);
    for (int i = no_of_disks; i >= 1; i--)
    {
        push(i, A);
    }
    printf("Initial stage: ");
    printf("tower A: ");
    printWhole(A);
    printf("tower B: ");
    printWhole(B);
    printf("tower C: ");
    printWhole(C);
    move(no_of_disks, A, C, B);
    return 0;
}