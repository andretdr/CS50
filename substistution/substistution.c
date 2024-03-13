#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check(string s);

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
    int n = strlen(s);
    if 

    return true;
}
