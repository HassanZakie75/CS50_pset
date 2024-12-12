#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    // char *t = s; // this will copy the same address, mean they will have the same address literally as t = s.
    char *t = malloc(strlen(s) + 1); // memory allocate
    if ( t == NULL) // if malloc return null mean there is no more memory
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++) // <= will copy all the characters
    {
        t[i] = s[i];
    }

    if  (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }


    printf("%s\n", s);
    printf("%s\n", t);

    free(t); // return the memory used by malloc back to the computer
}
