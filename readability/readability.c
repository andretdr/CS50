#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <bool.h>

int main(void)
{
    int tletters = 0;
    int twords = 0;
    int tsentences = 0;
    bool lastword = false; // to account for extra spaces to ensure correct wordcount
    bool lastsent = false; // to account for extra punctuations to ensure correct sentence count

    string text = get_string ("Text: ");

    // main loop
    for (int i = 0, n = strlen (text); i < n; i++)
    {
        char c = text[i];
        if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))  // if its a letter
        {
            tletter++;
            lastword = true;
        }
        else


    }


    printf ("%s\n", text);



}
