// keys and values
// words -> definitions

// hashtable
//

#include <ctype.h> // to upper

unsigned int hash(const char *word) // DONT change the *ptr value, const argument. unsigned. force the int. Hash function
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


