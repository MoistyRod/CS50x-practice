// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26*26*10;

// Hash table
node *table[N];

// Extra variables
unsigned int hash_value;
unsigned int word_count;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);
    node *ptr = table[hash_value];

    while (ptr != NULL)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int total = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }

    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    node *n = NULL;

    while(fscanf(file, "%s", word) != EOF)
    {
        n = malloc(sizeof(node));
        strcpy(n->word, word);
        hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *ptr = NULL;
    node *temp = NULL;

    for (int i = 0; i < N; i++)
    {
        ptr = table[i];

        while (ptr != NULL)
        {
            temp = ptr->next;
            free(ptr);
            ptr = temp;
        }
    }

    if (ptr == NULL)
    {
        return true;
    }

    return false;
}
