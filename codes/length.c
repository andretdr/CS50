#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Gimme name ");

    int n = 0;
    while (name[n] != '\0')
        n++;

    printf("Length is %i\n",n);

}
