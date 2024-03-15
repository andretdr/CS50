#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; // p is pointer var that stores the address of a int. &n is the address of n
    // when declaring a pointer, syntax is *p

    // when using the pointer var, just use p to return address
    // when want to GOTO the var address, use *p


    printf("%p\n",p); // p stores the address of n
    printf("%i\n",*p); // *p stores n (the value of n) goto the address of n
    )

}
