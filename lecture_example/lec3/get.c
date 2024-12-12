#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n); // scan get the value input %i and put it in address &n
    printf("n: %i\n", n);

    char *s;
    printf("s: ");
    scanf("%s", s); // scan get the value input %s and put it in address &n
    printf("n: %s\n", s);

    char d[4];
    printf("d: ");
    scanf("%s", d); // scan get the value input %s and put it in address &n
    printf("d: %s\n", d);
}
