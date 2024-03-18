#include <stdio.h>
//#include <>
//#include <>

int main(void)
{
    char *s; // pointers need to be initialised by malloc. the address needs to be assigned
    // or else you can
    // char s[4];

    printf("s: ");
    scanf("%s", s); // s is already an address, so still passing by reference
    printf("s: %s\n", s);

}



/*
    int n;
    printf("n: ");
    scanf("%i", &n); // the address of n passing by reference, not pasing by value // taking input
    printf("n: %i\n", n);
*/


}
