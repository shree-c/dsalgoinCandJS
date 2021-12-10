#include <stdio.h>
#define MAX 4
void enqueue_front(int *arr, int *f, int *r, int item)
{
    if (*f == -1)
    {
        arr[++*f] = item;
        ++*r;
        return;
    }
    if (*f == 0)
    {
        printf("queue full on front side\n");
        return;
    }
    else
    {
        arr[--*f] = item;
        return;
    }
}
void enqueue_rear(int *arr, int *f, int *r, int item)
{
    if (*r == MAX - 1)
    {
        printf("queue full on rear\n");
        return;
    }
    else if (*r == -1)
    {
        arr[++*r] = item;
        ++*f;
        return;
    }
    else
    {
        arr[++*r] = item;
        return;
    }
}
void dequeue_front(int *arr, int *f, int *r)
{
    if (*f == -1)
    {
        printf("queue empty\n");
        return;
    }
    else if (*f == *r)
    {
        printf("deleted %d\n", arr[*f]);
        *f = *r = -1;
        return;
    }
    else
    {
        printf("deleted %d\n", arr[(*f)++]);
        return;
    }
}
void dequeue_rear(int *arr, int *f, int *r)
{
    if (*r == -1)
    {
        printf("queue empty\n");
        return;
    }
    else if (*r == *f)
    {
        printf("deleted %d\n", arr[*r]);
        *f = *r = -1;
    }
    else
    {
        printf("deleted %d\n", arr[(*r)--]);
        return;
    }
}
void display(int *arr, int f, int r)
{
    if (f == -1)
    {
        printf("empty queue\n");
        return;
    }
    printf("%d---%d\n", f, r);
    for (int i = f; i <= r; i++)
    {
        printf("-->%d\n", arr[i]);
    }
}
int main()
{
    int arr[MAX];
    int f = -1, r = -1;
    int opt;
    do
    {
        printf("1.enqueue front\n2.enqueue back\n3.dqueue front\n4.dqueue_back\n5.display\n6.exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("enter the item: ");
            int item;
            scanf("%d", &item);
            enqueue_front(arr, &f, &r, item);
            break;
        case 2:
            printf("enter the item: ");
            int hold;
            scanf("%d", &hold);
            enqueue_rear(arr, &f, &r, hold);
            break;
        case 3:
            dequeue_front(arr, &f, &r);
            break;
        case 4:
            dequeue_rear(arr, &f, &r);
            break;
        case 5:
            display(arr, f, r);
            break;
        case 6:
            printf("byeee\n");
            break;
        default:
            printf("unknown option\n");
            break;
        }
    } while (opt != 6);
}