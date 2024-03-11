#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
//#include <atong.h>

void meow (int n);

int main(void)
{
    meow(6);
}


void meow(int n) // does nt return a value, and doesnt take in a parameter void, void
    {
        for (int i=0;i<n;i++)
        printf("meow \n");
    }




