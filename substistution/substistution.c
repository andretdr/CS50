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
    string lows = lowercase(s);
    int n = strlen(s);

    if (n == 26) // if 26 chars do other checks
    {
        for (int i = 0; i < n; i++)
        {
            char c = lows[i];
            if ((c >= 'a') && (c <= 'z'))
            {
                
            }
        }
    }
    else
    {
        printf("Key length is not 26");
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
