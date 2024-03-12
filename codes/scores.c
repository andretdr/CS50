#include <cs50.h>
#include <stdio.h>

int main(void)
{
/*    int score1 = 72;
    int score2 = 73;
    int score3 = 33;
*/
    int score[3];
    int total = 0;

    for (int i=0;i<3;i++)
    {
        score[i]=get_int("gimme score :");
        total = total + score[i];
    }

    printf("Average score %.2f\n",(total)/3.0);

}
