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

    //add a new node
    node *n = malloc(sizeof(node));
    n->number = 1; // (*n).number = 1; same
    n->next = NULL;

}
