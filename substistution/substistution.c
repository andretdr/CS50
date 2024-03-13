#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check(string s);
string lowercase(string s);

int main(int argc, string argv[])
{
    int exitval = 0;

    if (argc == 2) // if it just accepted 1 additional string input
    {
        check(argv[1]);
    }
    else
    {
        printf("Usage: ./substitution key");
        exitval = 1;
    }

    return exitval;
}

bool check(string s)
{
    bool retval = false;
    bool loopbreak = false;
    string lows = lowercase(s);
    int n = strlen(s);


    if (n == 26) // if 26 chars do other checks
    {
        int i = 0;
        while ((!loopbreak) || (i < n))   // for the length of the string, or error found
        {
            char c = lows[i];
            if ((c >= 'a') && (c <= 'z')) // check each character is a letter
            {
                
            }
            else
            {
                printf("Key requires only letters.\n");
                loopbreak = true;
            }

            i++;
        }
    }
    else
    {
        printf("Key length is not 26.\n");
    }

    return retval;
}

string lowercase(string s) // lowercases
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            s[i] = s[i] + 32;
        }
    }
    return (s);
}
