#include <stdio.h>
#include <cs50.h>
#include <string.h>

string codify(string s);

int main (void)
{
    int scoreboard[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

    string inputa = get_string("Player 1: ");
    string inputb = get_string("Player 2: ");

    string lca = codify(inputa);
    printf ("%i\n",lca[0]);
    printf ("%c\n",lca[0]);



}

string codify(string s) //lowercases and converts letters to correspond to a=1, b=2 etc
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            s[i] = s[i] + 32 - 96;
        }
    }
    return (s);
}
