#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

int typeCheck (long a); // 0=null, 1=Amex, 2=Master, 3=Visa
bool checkSum (long a, int t); // take in the number, and the type

int main(void)
{
    long cc;
    int type;
    bool valid = false;

    do
    {
        cc = get_long ("Enter CC number please: ");
    }
    while (cc < 1);

    type = typeCheck (cc);

    if (type > 0 & type < 4)
        valid = checkSum (cc, type);


    if (type == 1)
        printf("AMEX\n");
    else
        if (type == 2)
            printf("MASTER\n");
        else
            if (type == 3)
                printf("VISA\n");
            else
                printf("INVALID\n");

}


int typeCheck (long a) // 0=null, 1=Amex, 2=Master, 3=Visa
{
    long amexCheck = a/10000000000000;
    // amex check
    if ((amexCheck) == 34 || (amexCheck) == 37)
        return 1;
    else
    {   // master check
        long masterCheck = a/100000000000000;
        if ((masterCheck) > 50 & (masterCheck) < 56)
            return 2;
        else
        {
            long visaCheck1 = a/1000000000000;
            long visaCheck2 = a/1000000000000000;
            if ((visaCheck1) == 4 || (visaCheck2) == 4)
                return 3;
            else
                return 0;
        }
    }
}


bool checkSum (long a, int t)
{
    // check if 16 digits
    if

}
