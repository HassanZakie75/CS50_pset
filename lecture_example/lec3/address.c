#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; // stores the values of the address
    printf("%p\n", p); // p is known as pointer
    printf("%i\n", *p); // go to the given address

    string s = "Hi!";
    printf("%p\n", s);
    printf("%p\n", &s[0]); // get the same value, s is the address of the first characters
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}
