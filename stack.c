#include "stack.h"
int multiply(int a, int b)
{
    return a * b;
}
int main()
{
    stack *stk = newStack();
    int opt;
    printf("A stack has been created with the max-size of 100 elements.\n");
    do
    {
        printf("You can perform the following operations on stack:\n\t1. push\n\t2. pop\n\t3. print top element\n\t4. print whole stack\n\t5. clear the stack\n\t6. is empty?\n\t7. exit\nEnter the serial numbers to perform operations: ");
        if (scanf("%d", &opt) != 1)
        {
            opt = 0;
        }
        switch (opt)
        {
        case 1:
            printf("Enter the element to push: ");
            int ele;
            scanf("%d", &ele);
            push(ele, stk);
            break;
        case 2:
            if (!isEmpty(stk))
                printf("popped %d\n", pop(stk));
            else
                printf("stack empty!!!\n");
            break;
        case 3:
            if (!isEmpty(stk))
                printf("top element: %d\n", returnTop(stk));
            else
                printf("stack empty!!!\n");
            break;
        case 4:
            printWhole(stk);
            break;
        case 5:
            clear(stk);
            break;
        case 7:
            printf("bye\n");
            break;
        case 6:
            if (isEmpty(stk))
            {
                printf("yes");
            }
            else
            {
                printf("no");
            }
            break;
        case 8:
            int num;
            scanf("%d", &num);
            map(stk, multiply, num);
            printf("ok\n");
            break;
        default:
            printf("enter valid input!\n");
            break;
        }
    } while (opt != 7);
    return 0;
}