#include <cs50.h>
#include <stdio.h>

const int N = 3;

int main(void)
{
    int score[N];
    int total = 0;

    for (int i=0;i<N;i++)
    {
        score[i]=get_int("gimme score :");
        total = total + score[i];
    }

    printf("Average score %.2f\n",(total)/(float)N);

}
