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
            lastword = true; // consider this word once we come upon a ' '
            lastsent = true; // consider this sentence once we come upon a '.' '?' '!'
        }
        else
            if ((c == ' ') && (lastword)) // if char is a space, but there was a letter before that. to account for 2 or more spaces
            {
                twords++;
                lastword = false;
            }
            else
                if (((c == '.') || (c == '?') || (c == '!')) && lastsent)
                {
                    twords++;
                    tsentences++;
                    lastsent = false;
                    lastword = false;
                }


    }


    printf ("%s\n", text);



}
