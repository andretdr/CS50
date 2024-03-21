// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 456976; //26 ^ 4

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO check the word against the hash table dictionary, or if its not in the dict, its false
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int i = 0;
    unsigned int result = 1;
    while (word[i] != '\0') // not terminated
    {
        if (isalpha(word[i]))
        {
            result = toupper(word[i]) - 'A';
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) // dictionary is the file name
{
    // TODO create the hashtable and load the dictionary into it
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO size n of dictionary
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
