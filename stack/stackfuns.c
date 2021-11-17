#include "stack.h"
stack *newStack()
{
    stack *newStk = (stack *)malloc(sizeof(stack));
    newStk->stk = (int *)malloc(sizeof(int) * MAXSIZE);
    newStk->stkctr = 0;
    return newStk;
}
void push(int item, stack *stk)
{
    if (stk->stkctr == MAXSIZE)
    {
        printf("Error: stack full!!\n");
    }
    else
    {
        stk->stk[stk->stkctr++] = item;
    }
}
int pop(stack *stk)
{
    if (stk->stkctr == 0)
    {
        printf("Error: stack empty!!\n");
        return -1;
    }
    else
    {
        return stk->stk[--stk->stkctr];
    }
}
int returnTop(stack *stk)
{
    if (stk->stkctr == 0)
    {
        printf("Error: stack empty!!\n");
        return -1;
    }
    else
    {
        return stk->stk[stk->stkctr - 1];
    }
}
void printWhole(stack *stk)
{
    if (stk->stkctr == 0)
    {
        printf("Error: stack empty!!\n");
    }
    else
    {
        printf("[ ");
        for (int i = 0; i < stk->stkctr; i++)
        {
            printf("%d ", stk->stk[i]);
        }
        printf("]");
    }
}
void clear(stack *stack)
{
    stack->stkctr = 0;
    printf("cleared!!\n");
}
bool isEmpty(stack *stk)
{
    return (stk->stkctr == 0) ? true : false;
}
bool isFull(stack *stk)
{
    return (stk->stkctr == MAXSIZE) ? true : false;
}

int stacksize(stack *stk) {
    return stk->stkctr;
}

void map(stack *stk, int (*mapFun) (int, int), int mul) {
    for (int i = 0; i < stk->stkctr; i++) {
        stk->stk[i] = mapFun(stk->stk[i], mul);
    }
}
