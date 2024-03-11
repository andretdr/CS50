#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int counter = 0;

    while (counter < 3)
    {
        meow();
        counter++;
    }
}

/*
    for (int i = 0; i < 3; i++)
    {
        printf("meow \n");
    }
*/

//    while (true) //forever loop

// declaring functions

void meow(void) // does nt return a value, and doesnt take in a parameter void, void
    {
        printf("meow \n");
    }





