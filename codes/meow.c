#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
//#include <atong.h>

void meow (void);

int main(void)
{
    int counter = 0;

    while (counter < 3)
    {
        meow();
        counter++;
    }
}

void meow(void) // does nt return a value, and doesnt take in a parameter void, void
    {
        printf("meow \n");
    }




