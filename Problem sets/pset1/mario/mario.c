#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i, j, k;
xyz:
    k = get_int("Height: ");
    while (k < 1 || k > 8)
    {
        goto xyz;
    }

    for (i = k; i > 0; i--)
    {
        for (j = 0; j < i - 1; j++)
        {
            printf(" ");
        }

        for (j = 0; j < k - i + 1; j++)
        {
            printf("#");
        }

        printf("  ");

        for (j = 0; j < k - i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}