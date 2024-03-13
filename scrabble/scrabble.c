#include <stdio.h>
#include <cs50.h>
#include <string.h>

string lowercase(string s);
int addtotal(string s);

int main (void)
{
    string inputa = get_string("Player 1: ");
    string inputb = get_string("Player 2: ");

    int atotal = addtotal(lowercase(inputa));
    int btotal = addtotal(lowercase(inputb));

    if (atotal > btotal)
    {
        printf("Player 1 wins!\n");
    }
    else
        if (atotal < btotal)
        {
            printf("Player 2 wins!\n");
        }
        else
        {
            printf("Tie!\n");
        }
}

string lowercase(string s) //lowercases and converts letters to correspond to a=1, b=2 etc
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            s[i] = s[i] + 32; // - 97;
        }
        else // its not an uppercase alphabet
            if ((s[i] < 'a') || (s[i] > 'z')) // if also not a lowercase alphabet
            {
                s[i] = '{'; // this character will return 26 after the -97 operation, which will give the score of 0
            }
        }
    return (s);
}

int addtotal(string s) // add all the score according to score board
{
    int scoreboard[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10,0}; // last score 0 for any other char
    int total = 0;

    for (int i = 0, n = strlen(s); i < n; i++) //for length of string
    {
        total = total + scoreboard[(int)(s[i]-97)]; // cast the char into an int coressponding to 0=a,1=b etc
    }

    return total;
}
