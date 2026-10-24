#include <stdio.h>

/* Call by Value: copy of a and b is passed, originals do not change */
void swapByValue(int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

/* Call by Reference: addresses of a and b are passed, originals change */
void swapByReference(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a, b;

    /* Call by Value */
    a = 10;
    b = 20;
    swapByValue(a, b);
    printf("Call by Value:\n");
    printf("No1 = %d\n", a);
    printf("No2 = %d\n", b);

    /* Call by Reference */
    a = 10;
    b = 20;
    swapByReference(&a, &b);
    printf("\nCall by Reference:\n");
    printf("No1 = %d\n", a);
    printf("No2 = %d\n", b);

    return 0;
}
