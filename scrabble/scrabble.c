#include <stdio.h>
#include <cs50.h>
#include <string.h>

string codify(string s);
int addtotal(string s);

int main (void)
{
    string inputa = get_string("Player 1: ");
    string inputb = get_string("Player 2: ");

    string lca = codify(inputa);
    string lcb = codify(inputb);




}

string codify(string s) //lowercases and converts letters to correspond to a=1, b=2 etc
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            s[i] = s[i] + 32 - 97;
        }
        else
            if ((s[i] >= 'a') && (s[i] <= 'b'))
            {
                s[i] = s[i] - 97;
            }
    }
    return (s);
}

int addtotal(string s) // add all the score according to score board
{
    int scoreboard[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

    int i = (int)s[0]; // cast the char into an int


    //printf ("%i\n",lca[0]);
    //printf ("%c\n",lca[0]);
    //printf ("%i\n",scoreboard[i]);


}
