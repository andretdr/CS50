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

node *startptr = NULL;
node *currentptr = NULL;

bool addr(char *word);
bool checkr(const node *current, char *word);
void unloadr(node *current);
void printr(node *current);

int sized = 0;
int collisions = 0;

const unsigned int N = 856976; //26 ^ 4

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
    // TODO: take the 1st n 3rd letter n 5th letter, then + combined letters + 26*length
    int i = 0;
    unsigned int result = 0; // or else if 0 everything is 0
    int factor = 1;
    while ((word[i] != '\0') && (i < 5)) // not terminated. 26^0*word[0]+26^1*word[1]+26^2*word[2]+26^3*word[3]  // I disregard aphosrothes
    {

        if ((isalpha(word[i])) && (i != 1))
        {
            result += factor * (tolower(word[i]) - 'a');
            factor *= 26;
         }
        i++;
    }
    int n = 0;
    int totalletters = 0;
    while ((word[n] != '\0')) // calculate length, add all letters up
    {
        if ((isalpha(word[n])))
        {

            totalletters += (tolower(word[n]) - 'a');
//            printf("totalletters :%i\n",totalletters);

        }
        n++;
    }
    result += totalletters*26 + n*26*26;
//    printf ("hash %i %i %i\n",result, totalletters, n*26);

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
                currentptr = NULL;
                startptr = NULL;
                addr(word);
                index = 0;

                // add to hash table

/*
                // initialise node
                node *n = malloc(sizeof(node));
                n->next = NULL;

                for (int i = 0; i < LENGTH + 1; i++)
                {
                    n->word[i] = '\0';
                }
                for (int i = 0; i < index; i++)
                {
                    n->word[i] = word[i];
                }
                if (table[hash(n->word)] != NULL) // collision is true
                {
                    collisions++;
                }
*/



//                addr((&(table[hash(n->word)])), &n);
//                printf("hash for %s is %i \n",n->word,hash(n->word));
//                addr(&table[hash(n->word)], &n);

/*
                if (table[12846]!= NULL)
                    printf("direct check %s\n", (*table[12846]).word);

                if (table[346790]!= NULL)
                {
                    printf("direct check %s\n", (*table[346790]).word);
                    if (((*table[346790]).next) != NULL)
                    {
                        printf("direct check %s\n", (*(*table[346790]).next).word);
                        if (((*(*table[346790]).next).next) != NULL)
                            printf("direct check %s\n", (*(*(*table[346790]).next).next).word);
                    }
                }*///

                //free(n);

            }
    }

    fclose(file);

//        if (table[435164] != NULL)
//        printr(table[435164]);

    printf("Collisions :%i",collisions);
    return true;
}

bool addr(char *word)
{
    if (startptr == NULL) // if start of recursion hashtable
    {
        if (table[hash(word)] == NULL) // if 1st entry
        {
            // insert here
            node *n = malloc(sizeof(node));
            n->next = NULL;

            int i = 0;
            while (word[i] != '\0') // copy the word
            {
                n->word[i] = word[i];
                i++;
            }
            for (int j = i; j < LENGTH + 1; j++) // zerofy the rest
                n->word[j] = '\0';

            table[hash(word)] = n; // 1st entry assigned

            return true;
        }
        else // not 1st entry but start of recursion
        {
            currentptr = startptr = table[hash(word)];
            addr(word);
        }
    }
    else
    {
        if ()// check if toadd word <= to current word
        { // add


        }
        else
        {
            currentptr = currentptr->next;
            addr(word);
        }
    }
// BASE CASE
    if (currentptr == NULL)
    {
        // insert here
        node *n = malloc(sizeof(node));
        n->next = NULL;

        int i = 0;
        while (word[i] != '\0') // copy the word
        {
            n->word[i] = word[i];
            i++;
        }
        for (int j = i; j < LENGTH + 1; j++) // zerofy the rest
            n->word[j] = '\0';

        currentptr = n;

        return true;

    }



                if () // add word here, then
                // initialise node
                node *n = malloc(sizeof(node));
                n->next = NULL;

                for (int i = 0; i < LENGTH + 1; i++)
                {
                    n->word[i] = '\0';
                }
                for (int i = 0; i < index; i++)
                {
                    n->word[i] = word[i];
                }
                if (table[hash(n->word)] != NULL) // collision is true
                {
                    collisions++;
                }



}

bool checkr(const node *current, char *word)
{   // recursively check sorted linked list
    // BASE CASE

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

/*
bool addr(node **current, node **toadd) // you have to pass the ADDRESS EVERYTIME you want to pass by reference. Even when using pointers. hence.
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
                return addr(&((**current).next), toadd);
            }
}
*/


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return sized;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
            unloadr(table[i]);
        free(table[i]);
        table[i] = NULL;
    }

    if (table[435164] != NULL)
        printr(table[435164]);
    return true;
}

void printr(node *current)
{
    if (current->next == NULL)
        printf("%s \n",current->word);
    else
    {
        printr(current->next);
        printf("%s \n",current->word);
    }
}


void unloadr(node *current) // recursively unloads
{
    node *p = current->next;
    //BaseCASE
    if (p == NULL)
    {
 //       printf("unloading %s\n",current->word);
        //free(current);
    }
    else
    {
        unloadr(p);

//        free(current->word);
        free(p);
        p = NULL;

//        printf("unloading %s\n",current->word);
    }
}
