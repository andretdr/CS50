#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL; // the first pointer

    for (int i = 1; i < argc; i++)
    {
        int value = atoi(argv[i]); //convert string to int

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // free memory
            return 1;
        }
        n->number = value;

    }

    //add a new node

    n->number = 1; // (*n).number = 1; same
    n->next = NULL;

    free(node);

}
