#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; // stores the values of the address
    printf("%p\n", p); // p is known as pointer
    printf("%i\n", *p); // go to the given address

    char *s = "Hi!"; // no more chs50.h for training wheel
    printf("%p\n", s);
    printf("%p\n", &s[0]); // get the same value, s is the address of the first characters
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    printf("%c", s[0]); // get the characters
    printf("%c", s[1]);
    printf("%c", s[2]);
    printf("%c\n", s[3]);

    printf("%c", *s); // print using pointer arimethics
    printf("%c", *(s + 1));
    printf("%c\n", *(s + 2)); 
}
