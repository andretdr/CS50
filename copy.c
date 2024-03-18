#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // toupper tolower
#include <stdlib.h>


int main (void)
{
    string s =get_string("s: ");

    string t = malloc(strlen(s) + 1); // +1 for the null char

 //   *t = *s; // now t has the same address

    printf ("%s\n", *s);
//    printf ("%s\n", t);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // printf ("%s\n", s);
    // printf ("%s\n", t);



}
