#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

int typeCheck (long a); // 0=null, 1=Amex, 2=Master, 3=Visa
bool checkSum (long a); // take in the number

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
        valid = checkSum (cc);


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
            if (((visaCheck1) == 4) || ((visaCheck2) == 4))
                return 3;
            else
                return 0;
        }
    }
}


bool checkSum (long a)
{

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
            // mult by 2
            digit = digit * 2;
            // add up the digits
            int digitTens = (digit/10); // the digit in the 10s place
            totalMult = totalMult + digitTens + (digit - (digitTens*10));
            mult = false;
        }
        truncator = truncator * 10; // increase by 10
    }
    total = totalAdd + totalMult;

    if (total - (total/10)*10) == 0
        return true;
    else
        return false;
}
