#include <stdio.h>
#include <cs50.h>

int main()
{
    string name = get_string("Nama kau sapa: ");

    printf("Hello, %s\n", name);
}

