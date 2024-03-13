#include <stdio.h>
#include <cs50.h>
#include <string.h>

string codify(string s);
int addtotal(string s);

int main (void)
{
    string inputa = get_string("Player 1: ");
    string inputb = get_string("Player 2: ");

//    int atotal = addtotal(codify(inputa));
//    int btotal = addtotal(codify(inputb));
    string test = codify(inputa);

    printf ("%i %i %i %i\n",test[0],test[1],test[2],test[3]);
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
            if ((s[i] >= 'a') && (s[i] <= 'z'))
            {
                s[i] = s[i] - 97;
            }
    //        else // catch the zero
    //            s[i] = 0;
    }
    return (s);
}

int addtotal(string s) // add all the score according to score board
{
    int scoreboard[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int total = 0;

    for (int i = 0, n = strlen(s); i < n; i++) //for length of string
    {
        total += scoreboard[(int)s[i]]; // cast the char into an int
    }

    return total;
    //printf ("%i\n",lca[0]);
    //printf ("%c\n",lca[0]);
    //printf ("%i\n",scoreboard[i]);
}
