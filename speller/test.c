#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[2];
    struct node *next;
} node;


int main (void)
{



    node *table[5];
    node *n = malloc(sizeof(node));
    n->word[0] = 'h';
    n->word[1] = '\0';
    table[0] = n;
    printf("%s\n",(*table[0]).word);
    table[0]->next = n;
    printf("%s\n",(*(*table[0]).next).word);

    free(n);
}
