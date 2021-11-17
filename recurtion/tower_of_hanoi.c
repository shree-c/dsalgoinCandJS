#include <stdio.h>
void move(int i, char start, char end, char hold)
{
    if (i > 0) {
        move(i - 1, start, hold, end);
        printf("Move %d from %c to %c\n", i, start, end);
        move(i - 1, hold, end, start);
    }
    // if (i == 1)
    // {
    //     printf("Move disk %d from %c tower to %c tower.\n", i, start, end);
    //     return;
    // }
    // move(i - 1, start, hold, end);
    // printf("Move disk %d from %c tower to %c tower.\n", i, start, end);
    // move(i - 1, hold, end, start);
}
int main()
{
    printf("***********Tower Of Hanoi******************\n");
    printf("Enter the number of disks you want in first tower: ");
    int i;
    scanf("%d", &i);
    move(i, 'A', 'C', 'B');
    return 0;
}
