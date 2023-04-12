// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

typedef uint8_t BYTE;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int words;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    while (table[index])
    {
        if (strcasecmp(table[index]->word, word) == 0)
        {
            return true;
        }
        table[index] = table[index]->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // tolower(word[0]);
    char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < N; i++)
    {
        if (word[0] == lower[i])
        {
            return i;
        }
        else if (word[0] == upper[i])
        {
            return i;
        }
    }
    return N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fclose(dict);
        return false;
    }
    char strings [8];
    while (fscanf(dict, "%s", strings) != EOF)
    {
        words ++;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, strings);
        n -> next = NULL;
        int index = hash(strings);
        n -> next = table[index];
        table[index] = n;
        // free(n);
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return true;
}
