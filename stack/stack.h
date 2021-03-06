#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 
#include <stdbool.h>
typedef struct
{
    int *stk;
    int stkctr;
    char *name;
} stack;

stack *newStack();

void push(int, stack *);

int pop(stack *);

int returnTop(stack *);

void printWhole(stack *);

void clear(stack *);

bool isFull(stack *);

bool isEmpty(stack *);

int stacksize(stack *);

void map(stack *, int (*)(int, int), int);
