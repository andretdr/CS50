#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; // p is pointer var that stores the address of a int. &n is the address of n

    printf("%p\n",p); // p stores the address of n
    printf("%p\n",p); // *p stores n (the value of n)
    )

}
