// Luhn's Algorithm Checksum for credit card by Hassan Zakie Yusoff
#include <cs50.h>
#include <stdio.h>

bool luhn_checksum(long card_number) // Luhn's Algorithm checksum
{
    int sum = 0, alternate = false; // setting up intial variables
    while (card_number > 0)
    {
        int digit = card_number % 10; // extract last digit using modulo operator
        card_number /= 10;            // remove last digit using integer division

        if (alternate) // if alternate digit, doubled
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;           // sum all the doubled number
        alternate = !alternate; // togled the alternate as its goes through all the digit
    }

    return sum % 10 == 0; // checked the sum divisibility with 10
}

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: "); // input of credit card number
    }
    while (card_number < 1); // remove input bellow 1 value and negative value

    long first_2_digits = card_number; // initial value for variable
    int count = 0;
    long number = card_number;

    while (number > 0) // counting the total amount of digit in the credit card number
    {
        count++;
        number = number / 10;
    }

    while (first_2_digits >= 100) // counting the 2 inital number of the credit card
    {
        first_2_digits = first_2_digits / 10;
    }
    // printf("no of digit: %i\n", count); // use if want to check the number of digit counted
    // printf("first two digit number is: %li\n", first_2_digits) // use if want to check the number
    // of first two digit

    if (luhn_checksum(card_number)) // if card is valid, it will check other property
    {
        if (count == 15 && (first_2_digits == 34 || first_2_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && (first_2_digits >= 51 && first_2_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if (first_2_digits /= 10, (count == 13 || count == 16) && first_2_digits == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
