#include <stdio.h>
int fac(int i) {
    if (i == 0)
        return 1;
    else
        return i * fac(i - 1);
}
int main() {
    while (1) {
        printf("enter the number to find its factorial: ");
        int i;
        scanf("%d", &i);
        printf("the factorial of %d is %d\n", i, fac(i));
    }
    return 0;
}
