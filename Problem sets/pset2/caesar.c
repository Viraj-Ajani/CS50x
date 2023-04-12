#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        if (key == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        string pt = get_string("plaintext: ");

        int len = strlen(pt), i, j;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < 26; j++)
            {
                if (pt[i] == lower[j])
                {
                    j = (j + key) % 26;
                    pt[i] = lower[j];
                }
                else if (pt[i] == upper[j])
                {
                    j = (j + key) % 26;
                    pt[i] = upper[j];
                }
                else
                {
                    continue;
                }
            }
        }

        printf("ciphertext: %s\n", pt);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}