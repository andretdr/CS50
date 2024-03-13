#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checknum(string s);
bool checkletters(string s);
bool checkunique(string s);
string lowercase(string s);


int main(int argc, string argv[])
{
    int exitval = 0;
    bool num = false;

    if (argc == 2) // if it just accepted 1 additional string input
    {
        if (checknum(argv[1])) // if it has 26 chars
        {
            if (checkletters(argv[1])) // if has only letters
            {
                if (!checkunique(argv[1])) // if NOT has unique letters only
                {
                    printf("Key must have 26 unique letters\n");
                    exitval = 1;
                }
            }
            else
            {
                printf("Key must only contain letters\n");
                exitval = 1;
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
    bool noissue = true;

    while ((noissue) && (i < n))   // for the length of the string, or error found
    {
        char c = lows[i];
        if ((c >= 'a') && (c <= 'z')) // check each character is a letter
        {
            printf ("%c",c);
        }
        else
        {
            noissue = false;
        }
        i++;
    }
    return noissue;
}

bool checkunique(string s)
{
    int check[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // 26 zeros for each letter
    bool noissue = true;
    int n = strlen(s);

    for (int i = 0; i < n; i++) // counting the number of each letter occurance
    {
        check[(int) (s[i] - 97)] ++; // increasing the count on each occurance of each letter. a=0, b=1 ...
    }

    int k = 0;
    while ((noissue) && (k < n)) //for the length of the string, check if all 1s
    {
        if (check[k]!=1)
        {
            noissue = false;
        }

        k++;
    }
    return noissue;
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
