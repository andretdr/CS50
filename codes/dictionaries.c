// keys and values
// words -> definitions

// hashtable
//

#include <ctype.h> // to upper

int hash(const char *word) // hash function
{
    return toupper(word[0]) - 'A';
}

typedef struct node
{
    char *names;
    char *number;
    struct node *next;
} node;

node *table[26][26];


