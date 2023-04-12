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
    //finding minimum no. of coins 
    while (cent > 0)
    {
        if (cent >= 25)
        {
            cent -= 25;
            coin ++;
        }
        else if (cent >= 10)
        {
            cent -= 10;
            coin ++;
        }
        else if (cent >= 5)
        {
            cent -= 5;
            coin ++;
        }
        else
        {
            cent -= 1;
            coin ++;
        }
    }
    //printing no. of coin
    printf("%i\n", coin);
}