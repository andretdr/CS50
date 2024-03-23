// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

bool add(node **current, node **toadd);
bool checkr(const node *current, char *word);

int sized = 0;

const unsigned int N = 456976; //26 ^ 4

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO check the word against the hash table dictionary, or if its not in the dict, its false
    char temp[LENGTH + 1] = {'\0'};
    int i = 0;

    while (word[i] != '\0')
    {
        if (isalpha(word[i]))
        {
            temp[i] = tolower(word[i]);
         //   printf("lower :%c\n", tolower(word[i]));
        }
        i++;
    }
  //  printf("word to check: %s %s \n", temp, word);
    return checkr(table[hash(word)], temp);

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function I can reduce the 26 factor to something smaller that fits the dictionary, then reduce N
    int i = 0;
    unsigned int result = 0; // or else if 0 everything is 0
    while ((word[i] != '\0') && (i < 4)) // not terminated. 26^0*word[0]+26^1*word[1]+26^2*word[2]+26^3*word[3]  // I disregard aphosrothes
    {
        if (isalpha(word[i]))
        {
            int factor = 1;
            for (int j = 0; j < i; j++)
            {
                factor *= 26;
            }
            result += factor * (tolower(word[i]) - 'a');
        }
        i++;
    }
    return result;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) // dictionary is the file name. my dictionary is lowercased
{
    // TODO create the hashtable and load the dictionary into it

    //create a node container.

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary\n");
        return 1;
    }

    char c;
    char word[LENGTH + 1]; // +1 for the terminator
    int index = 0;

    int test[5] = {0};
    int count = 0;

    while (fread(&c, sizeof(char), 1, file))
    {
        if ((isalpha(c)) || ((c == '\'') && index > 0))
        {
            word[index] = c; // dictionary is already lowercase
            index++;
        }
        else
            if ((c == '\n') && (index != 0))
            {
                word[index] = '\0';

                // add to hash table
//                printf("word to add %s, hash number %i\n",word , hash(word));
                // initialise node
                node *n = malloc(sizeof(node));
                n->next = NULL;
                for (int i = 0; i < index; i++)
                {
                    n->word[i] = word[i];
                }
                add(&table[hash(n->word)], &n);
/*
                if (table[109879]!= NULL)
                {
                    printf("direct check %s\n", (*table[109879]).word);
                    if (((*table[109879]).next) != NULL)
                    {
                        printf("direct check %s\n", (*(*table[109879]).next).word);
                        if (((*(*table[109879]).next).next) != NULL)
                            printf("direct check %s\n", (*(*(*table[109879]).next).next).word);
                    }
                }
*/
                index = 0;
            }
    }
    return true;
}

bool checkr(const node *current, char *word)
{   // recursively check sorted linked list
    // BASE CASE

    //printf("current->word: %s\n",current->word);
    if (current == NULL)
    {
        return false;
    }
    else
    {
        int compare = strcmp(word, current->word);
        if (compare == 0)
        {
            return true;
        }
        else
            if(compare > 0)
            {
                return checkr(current->next, word);
            }
            else
                return false; // if Null or compare > 0
    }
}

bool add(node **current, node **toadd) // you have to pass the ADDRESS EVERYTIME you want to pass by reference. Even when using pointers. hence.
{   // recursively add to sorted linked list
    // BASE CASE
    //printf("word to add %s\n",(**toadd).word);
    if (*current == NULL)
    {
        *current = *toadd;
        sized++;
  //      printf("inside,%s\n",(**current).word);
  //      printf("added word was stored overidding NULL\n");
        return true;

    }
    else
        if (strcmp((**toadd).word,(**current).word) <= 0) // if toadd node is smaller then current node, then add it here
        {
            (**toadd).next = *current;
            *current = *toadd;
 //           printf("added word inbetween\n");
            sized++;
            return true;
        }
        else
            {
                return add(&((**current).next), toadd);
            }

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return sized;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
