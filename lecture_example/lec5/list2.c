#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]); //atoi is ascII to integer
        // printf("%s\n", number);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // free memory thus far
        }
        n->number = number;
        // n->next = NULL; not needed as we have the next line already
        n->next = list;
        list = n;
    }

    // print the whole list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n",ptr->number);
        ptr = ptr->next;
    }
}
