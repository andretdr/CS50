#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL; // the first pointer
    node *n = malloc(sizeof(node));

}
