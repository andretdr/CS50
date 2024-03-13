#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checknum(string s);
bool checkletters(string s);
string lowercase(string s);


int main(int argc, string argv[])
{
    int exitval = 0;
    bool num = false;

    if (argc == 2) // if it just accepted 1 additional string input
    {
        if (checknum(argv[1])); // if it has 26 chars
        {
            if (checkletters(argv[1])) // if has only letters
            {

            }
        }
        else
        {
            printf("Key must have 26 unique letters\n");
            exitval = 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        exitval = 1;
    }

    return exitval;
}

bool checknum(string s)
{
    int n = strlen(s);
    if (n == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkletters(string s)
{
    int i = 0;
    int n = strlen(s);
    string lows = lowercase(s);
    bool loopbreak = false;

    while ((!loopbreak) && (i < n))   // for the length of the string, or error found
    {
        char c = lows[i];
        if ((c >= 'a') && (c <= 'z')) // check each character is a letter
        {
            printf ("%c",c);
        }
        else
        {
            printf("Key requires only letters.\n");
            loopbreak = true;
        }
        i++;
    }
}





    }


    bool retval = false;
    bool loopbreak = false;
    string lows = lowercase(s);
    int n = strlen(s);
    int lettercheck[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        int i = 0;
        while ((!loopbreak) && (i < n))   // for the length of the string, or error found
        {
            char c = lows[i];
            if ((c >= 'a') && (c <= 'z')) // check each character is a letter
            {
                printf ("%c",c);
            }
            else
            {
                printf("Key requires only letters.\n");
                loopbreak = true;
            }
            i++;
        }
        printf ("\n");
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
