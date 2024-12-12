// Prints Mario's pyramid at the end of the stage

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: "); // get the height of the pyramid ( by block)
    }
    while (n < 1);

    for (int i = 1; i <= n; i++) // determine the number of row
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" "); // print the space, n - 1 will reduce the number of space as # increase
        }

        for (int j = 1; j <= i; j++) // loop make number # = n
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
