#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int tletters = 0;
    int twords = 0;
    int tsentences = 0;

    float L = 0;
    float S = 0;


    bool lastword = false; // to account for extra spaces to ensure correct wordcount
    bool lastsent = false; // to account for extra punctuations to ensure correct sentence count

    string text = get_string ("Text: ");

    // main loop
    for (int i = 0, n = strlen (text); i < n; i++)
    {
        char c = text[i];
        if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))  // if its a letter
        {
            tletters++;
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

    L = (tletters / twords) * 100;
    S = (tsentences / twords) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    printf ("totalletters %i\n", tletters);
    printf ("totalwords %i\n", twords);
    printf ("totalsentences %i\n", tsentences);
    printf ("index %.2f\n", index);
}
