#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = get_int("i: ");
    int j = get_int("j: ");

    if (i == j)
    {
        printf ("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    char *s = get_string("s: ");
    char *t = get_string("t: ");

    printf("%s\n", s); // print will look similar
    printf("%s\n", t);
    printf("%p\n", s); // but location are actually different
    printf("%p\n", t);

    // if (s == t) // different no matter what because they are checking initial address of both string and not the letter of the string itself.
    if (strcmp(s,t) == 0)
    {
        printf ("Same\n");
    }
    else
    {
        printf("Different\n");
    }

}
