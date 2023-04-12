#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int letter_count(string text);
float word_count(string text);
int sentence_count(string text);

int main(void)
{
    // Rading Text form user
    string Text = get_string("Text : ");

    // Calculating letters per 100 words and sentence per 100 words
    float L = letter_count(Text) / word_count(Text) * 100;
    float S = sentence_count(Text) / word_count(Text) * 100;

    // Calculating index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    index = round(index);

    // Printing Grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }
}

int letter_count(string text)
{
    // Calculating no. of letter
    int i, letter = 0;

    int len = strlen(text);

    for (i = 0; i < len; i++)
    {
        text[i] = (int) text[i];
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letter++;
        }
    }

    return letter;
}

float word_count(string text)
{
    // Calculating no. of words
    int i, word = 1;

    int len = strlen(text);

    for (i = 0; i < len; i++)
    {
        text[i] = (int) text[i];
        if (text[i] == 32)
        {
            word++;
        }
    }

    return (float) word;
}

int sentence_count(string text)
{
    // Calculating no. of sentence
    int i, sentence = 0;

    int len = strlen(text);

    for (i = 0; i < len; i++)
    {
        text[i] = (int) text[i];
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentence++;
        }
    }

    return sentence;
}

int space_count(string text)
{
    // Calculating no. of space
    int i, space = 0;

    int len = strlen(text);

    for (i = 0; i < len; i++)
    {
        text[i] = (int) text[i];
        if (text[i] == 32)
        {
            space++;
        }
    }

    return space;
}