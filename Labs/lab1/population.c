#include <stdio.h>

int main(void)
{
    // Declaring variables
    int start, end, born, dead, n = 0, i;
    //Prompting user for Starting population
    do
    {
        printf("Start size : ");
        scanf("%d", &start);
    }
    while (start < 9);
    
    //Promptimg user for Ending Population
    do
    {
        printf("End size : ");
        scanf("%d", &end);
    }
    while (end < start);
    
    //Calculating number of years required for reaching ending population
    for (i = 0; n < end; i++)
    {
        if (start == end)
        {
            break;
        }
        born = start / 3;
        dead = start / 4;
        n = start + born - dead;
        start = n;
    }
    //Printing the result
    printf("Years: %d\n", i);
}