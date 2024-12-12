#include <cs50.h>  // run specialized code from cs50 to ease learning C
#include <stdio.h> // standart input output

int main()
{
    string Name_1 = get_string("What's your name? ");
    // ask user input in the form of string

    printf("hello, %s\n", Name_1); // replied to user
    return 0;
}
