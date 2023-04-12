/*

TO DO
if number does not satisfies condition of any card show it as invalid
if number satisfies condition show company name, the conditions are:
American Express uses 15-digit numbers  All American Express numbers start with 34 or 37 (print AMEX)
MasterCard uses 16-digit numbers MasterCard numbers start with 51, 52, 53, 54, or 55 (print MASTERCARD)
Visa uses 13- and 16-digit numbers all Visa numbers start with 4 (print VISA)

*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card_no = get_long("Number : ");
    int i = 0, x = 0, y = 0, b, a, q = 1, c;
    //printf("%li\n", card_no);

    while (card_no >= 10)
    {
        q++;
        if (i == 0)
        {
            a = card_no % 10;
            card_no = card_no / 10;
            x += a;
            i = 1;
        }
        else
        {
            b = card_no % 10;
            c = b;
            card_no = card_no / 10;
            b *= 2;
            if (b >= 10)
            {
                int z = b % 10;
                y += z;
                b /= 10;
            }
            y += b;
            i = 0;
        }
    }

    if (i == 0)
    {
        x += card_no;
    }
    else
    {
        b = card_no * 2;
        if (b >= 10)
        {
            int z = b % 10;
            y += z;
            b /= 10;
        }
        y += b;
    }

    int v = (x + y) % 10;

    if (card_no == 4 && q >= 13 && q <= 16 && v == 0)
    {
        printf("VISA\n");
    }
    else if (card_no == 3 && q == 15 && v == 0 && (c == 4 || c == 7))
    {
        printf("AMEX\n");
    }
    else if (card_no == 5 && q == 16 && v == 0 && a >= 1 && a <= 5)
    {
        printf("MASTERCARD\n");
    }
    else if (v == 0)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}