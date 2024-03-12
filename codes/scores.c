#include <cs50.h>
#include <stdio.h>

int main(void)
{
/*    int score1 = 72;
    int score2 = 73;
    int score3 = 33;
*/
    int score[3];

    for (int i=0;i<3;i++)
    {
        score[i]=get_int("gimme score :");
    }

    printf("Average score %.2f\n",(72+73+33)/3.0);

}
