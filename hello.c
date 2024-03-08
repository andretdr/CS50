#include <stdio.h> // header file
#include <cs50.h>  // input

int main(void)
{


    printf("hello world!\n");
    string nameVar = get_string("What's your name? ");
    string numberVar = get_string("What's your number? ");
    printf("hello %s, with number %s\n", nameVar, numberVar);

}
