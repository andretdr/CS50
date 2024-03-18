#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // toupper tolower
#include <stdlib.h>


int main (void)
{
    char *s =get_string("s: ");
    if (s == NULL) // not enough mem
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1); // +1 for the null char. char *t or string.
    if (t == NULL) // not enough mem available
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++) // remember to copy the last null char // or strcopy
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

    free(t); // free your malloc
    return 0;

}
