#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int amount; // ensure only acceptable input
    do
    {
        amount = get_int("Change owe: "); // getting the amount of changes
    }
    while (amount < 1);

    int coin25 = amount / 25; // calculating amount of 25 cent
    amount %= 25;             // finding balance for next calculation

    int coin10 = amount / 10; // calculating amount of 10 cent
    amount %= 10;

    int coin5 = amount / 5; // calculating amount of 5 cent
    amount %= 5;

    int coin1 = amount; // calculating amount of 1 cent

    printf("%i\n", coin25 + coin10 + coin5 + coin1); // calculating total number of coins

    return 0;
}
