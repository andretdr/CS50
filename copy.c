#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // toupper tolower


int main (void)
{
    string s =get_string("s: ");

    string t = s; // now t has the same address
    t[0] = toupper(t[0]);


    printf ("%s\n", s);
    printf ("%s\n", t);



}
