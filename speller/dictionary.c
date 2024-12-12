// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash the word to obtain its hash value
    int index = hash(word);
    node *cursor = table[index];
    // Search the hash table at location specific by the word's hash value
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
        // Return true if the word is found
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }
    return false; // Return false if no word is found
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hashval = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        hashval += tolower(word[i]);
        hashval = (hashval * tolower(word[i])) % N;
    }

    return hashval;
}

unsigned int word_count = 0; // Word count for the size function
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    // check if dictionary open properly
    if (source == NULL)
    {
        printf("Error opening dictionary\n");
        return 1;
    }

    // Read each word in the file
    char word[LENGTH + 1];
    while (fscanf(source, "%s", word) != EOF)
    {
        // Create space for a new node
        node *Node = malloc(sizeof(node));
        if (Node == NULL)
        {
            fclose(source);
            printf("Memory allocation failed\n");
            return 2;
        }

        // Copy the word into the new node
        strcpy(Node->word, word);

        // Hash the word to obtain hash value
        int index = hash(word);

        // Insert the new node into the hash table (using the index specified by its hash value)
        Node->next = table[index];
        table[index] = Node;

        // Increment of the word count
        word_count++;
    }
    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++) // Iterate through hash table
    {
        node *cursor = table[i]; // For each index, itereate through the linked list of nodes
        while (cursor != NULL)
        {
            // Free nodes, create temporary pointer
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL; // clear hash table
    }
    return true;
}
