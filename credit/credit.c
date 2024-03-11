#include <cs50.h>
#include <stdio.h>

int typeCheck (long a); // 0=null, 1=Amex, 2=Master, 3=Visa

int main(void)
{
    long cc;
    do
    {
        cc = get_long ("Enter CC number please: ");
    }
    while (cc < 1);

    typeCheck (cc);



}




int typeCheck (long a) // 0=null, 1=Amex, 2=Master, 3=Visa
{
    long amexCheck = a/10000000000000;
    // amex check
    printf ("%li\n", amexCheck);
    if ((amexCheck) == 34 || (amexCheck) == 37)
        return 1;
    else
        return 0;
}

