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
        n->next = list; // NEW node pointing to 1st node
        list = n; // list points to new node
    }

    // print
    



    free(node);

}
