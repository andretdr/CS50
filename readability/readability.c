#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int tletters = 0;
    int twords = 0;
    int tsentences = 0;
    bool 

    string text = get_string ("Text: ");

    // main loop
    for (int i = 0, n = strlen (text); i < n; i++)
    {
        char c = text[i];
        if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))  // if its a letter
        {
            tletter++;
        }


    }


    printf ("%s\n", text);



}
