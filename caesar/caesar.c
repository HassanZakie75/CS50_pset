// Caesar encrpytion using inpu as a key by Hassan Zakie
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate_char(char c, int key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a 'string' to an 'int'
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];
        printf("%c", rotate_char(c, key));
    }
    printf("\n");
}
// Make sure every character in argv[1] is a digit
bool only_digits(string s)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Rotate the character if it's a letter
char rotate_char(char c, int key)
{
    if (isalpha(c))
    {
        char offset = isupper(c) ? 'A' : 'a';
        int new_position = ((c - offset + key) % 26) + offset;
        return new_position;
    }
    else
    {
        return c;
    }
}
