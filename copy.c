#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // toupper tolower
#include <stdlib.h>


int main (void)
{
    string s =get_string("s: ");

    string t = malloc(strlen(s) + 1); // +1 for the null char

    for (int i = 0, n = strlen(s); i <= n; i++) // remember to copy the last null char
    {
        t[i] = s[i];
    }

//    printf ("%s\n", s);
//    printf ("%s\n", t);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf ("%s\n", s);
    printf ("%s\n", t);



}
