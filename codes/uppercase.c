#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string ("Input  :");


    printf("Output :");

    for (int i = 0, l = strlen(name); i < l; i++)
    {
        printf("%c", toupper(name[i]));

/*
        if (name[i]>='a' && name[i]<='z')
        {
            printf("%c", toupper(name[i]));    //name[i] - 32);
        }
        else
            printf("%c",name[i]);

*/

    }
    printf("\n");




}
