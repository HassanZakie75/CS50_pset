#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);  // have to use & for address
    printf("x is %i, y is %i\n", x, y);
}

void swap( int *a, int *b) // Use *a instead of a, to swap address instead of swap value only
                           // Value swap will not work
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
