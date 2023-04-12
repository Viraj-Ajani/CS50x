#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //declaring variable
    float dollar;
    //prompting user for non-negative value
    do
    {
        dollar = get_float("Change Owed : ");
    }
    while (dollar < 0);
    //declaring counter and getting cents from dollars
    int coin = 0, cent = round(dollar * 100);
    printf("%i\n", cent);
    //finding minimum no. of coins 
    while (cent > 0)
    {
        if ((cent - 25) >= 0)
        {
            printf("25,1\n");
            cent -= 25;
            coin += 1;
            printf("cent %i\n", cent);
            printf("coin %i\n", coin);
        }
        else if ((cent - 10) >= 0)
        {
            printf("10,1\n");
            cent -= 10;
            coin += 1;
            printf("cent %i\n", cent);
            printf("coin %i\n", coin);
        }
        else if ((cent - 5) >= 0)
        {
            printf("5,1\n");
            cent -= 5;
            coin += 1;
            printf("cent %i\n", cent);
            printf("coin %i\n", coin);
        }
        else
        {
            printf("1,1\n");
            cent -= 1;
            coin += 1;
            printf("cent %i\n", cent);
            printf("coin %i\n", coin);
        }
    }
    //printing no. of coin
    printf("%i\n", coin);
}