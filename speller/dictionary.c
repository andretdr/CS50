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

//typedef struct indexnode // this stores a list of all used indexes
//{
//    int index;
//    struct indexnode *next;

//} indexnode;

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
    unsigned int result = 0; // or else if 0 everything is 0
    while ((word[i] != '\0') || (i < 4)) // not terminated. 26^0*word[0]+26^1*word[1]+26^2*word[2]+26^3*word[3]  // I disregard aphosrothes
    {
        if (isalpha(word[i]))
        {
            int factor = 1;
            for (int j = 0; j < i; j++)
            {
                factor *= 26;
            }
            result += factor * (toupper(word[i]) - 'A');
        }
        i++;
    }
    return result;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) // dictionary is the file name
{
    // TODO create the hashtable and load the dictionary into it

    //create a node container.
    node *n = malloc(sizeof(node));

    FILE *file = fopen(dictionary, 'r');
    if (file == NULL)
    {
        printf("Cannot open dictionary");
        return 1;
    }

    char c;
    char word[LENGTH + 1]; // +1 for the terminator
    int index = 0;

    while (fread(&c, sizeof(char), 1, file));
    {
        if ((isalph(c)) || ((c == '\'') && index > 0))
        {
            word[index] = toupper(c); // upper case all my dictionary
            index++
        }
        else

    }

    add(n)



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
