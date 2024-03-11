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

    if (type > 0 & type < 5)
        valid = checkSum (cc, type);


    if (type == 1)
        printf("AMEX\n");
    else
        if (type == 2)
            printf("MASTER\n");
        else
            if (type == 3 || type == 4)
                printf("VISA\n");
            else
                printf("INVALID\n");

}


int typeCheck (long a) // 0=null, 1=Amex, 2=Master, 3=Visa 13 digit, 4=Visa 16 digit
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
            if ((visaCheck1) == 4)
                return 3;
            else
                if ((visaCheck2) == 4)
                    return 4;
                else
                    return 0;
        }
    }
}


bool checkSum (long a, int t)
{
    // if t == 1, length is 15. t == 2, length is 16. t = 3, length is 13. t = 4, length is 16
    //if

    bool mult = false; // doing the mult operation when true, add operation when false
    long truncator = 1;
    int totalAdd = 0;
    int totalMult = 0;
    int total = 0;

    while (a/truncator > 0) //quit when 0
    {
        if (!mult) // if add operation
        {
            //get the digit
            int digit = (a/truncator) - ((a/(truncator*10))*10);
            printf ("odd number %i\n",digit);
            totalAdd = totalAdd + digit;
            mult = true;
        }
        else // if mult operation
        {
            //get the digit
            int digit = (a/truncator) - ((a/(truncator*10))*10);
            printf ("even number %i\n", digit);
            // mult by 2
            digit = digit * 2;
            // add up the digits
            printf ("after mult 2 %i\n", digit);
            int digitTens = (digit/10)*10; // the digit in the 10s place
            totalAdd = totalAdd + digitTens + (digit - (digitTens*10));
            mult = false;
        }
        truncator = truncator * 10; // increase by 10
    }
    total = totalAdd + totalMult;
    printf ("TOTAL %i\n", total);

    return true;
}
