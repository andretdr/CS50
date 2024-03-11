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

printf("%li\n",cc/10);



}




int typeCheck (long a) // 0=null, 1=Amex, 2=Master, 3=Visa
{
    if (a/


}

