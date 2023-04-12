#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int keylen = strlen(argv[1]), k, l;
        if (keylen != 26)
        {
            goto end;
        }
        
        for (k = 0; k < keylen; k++)
        {
            if ((argv[1][k] >= 65 && argv[1][k] <= 90) || (argv[1][k] >= 97 && argv[1][k] <= 122))
            {
                continue;
            }
            else
            {
                goto end;
            }
        }
        
        for (k = 0; k < keylen; k++)
        {
            for (l = 0; l < 26; l++)
            {
                if (l == k)
                {
                    continue;
                }
                else if (argv[1][k] == argv[1][l])
                {
                    goto end;
                }
            }
        }
        
        // get_string function is function in cs50 library to get string from user and re-prompt user if he/she doesn't correspond
        string pt = get_string("plaintext: ");

        int len = strlen(pt), i, j, flag;
        
        printf("ciphertext: ");
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < 26; j++)
            {
                flag = 0;
                if (pt[i] == upper[j])
                {
                    if (isupper(argv[1][j]))
                    {
                        printf("%c", argv[1][j]);
                        flag = 1;
                        break;                    
                    }
                    else
                    {
                        char temp = argv[1][j];
                        temp -= 32;
                        printf("%c", temp);
                        flag = 1;
                        break;
                    }

                }
                else if (pt[i] == lower[j])
                {
                    if (islower(argv[1][j]))
                    {
                        printf("%c", argv[1][j]);
                        flag = 1;
                        break;                    
                    }
                    else
                    {
                        char temp = argv[1][j];
                        temp += 32;
                        printf("%c", temp);
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    continue;
                }
            }
            if (flag == 0)
            {
                printf("%c", pt[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
end:
        printf("Usage: ./substituion key\n");
        return 1;
    }
}