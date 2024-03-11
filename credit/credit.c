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



    if (typeCheck (cc) == 1)
    {
        printf("AMEX\n");
    }



}




int typeCheck (long a) // 0=null, 1=Amex, 2=Master, 3=Visa
{
    long amexCheck = a/10000000000000;
    // amex check
    long visaCheck;
    if ((amexCheck) == 34 || (amexCheck) == 37)
        return 1;
    else
    {   // master check
        long masterCheck = a/100000000000000;
        if ((masterCheck) > 50 & (masterCheck) < 56)
            return 2;
        else
        {
            long visaCheck = a/
            if
        }
    }
}

