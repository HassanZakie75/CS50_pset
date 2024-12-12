// 26 alpahabet encrpytion by Hassan Zakie
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_alphas(string s);
bool is_unique(string s);

int main(int argc, string argv[]) // single command-line argument input
{
    if (argc != 2)
    {
        printf("Usage: ./subtitution key\n");
        return 1;
    }
    string key = argv[1]; // cheking key validity

    if (!only_alphas(key) || !is_unique(key) ||
        strlen(key) != 26) // Make sure every character in argv is alphabet , unique and 26 char
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Promt user for input plainttext
    string plaintext = get_string("plaintext: ");

    // Assign alphabet character with encrypted character
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char c = plaintext[i];
            int j = isupper(c) ? c - 'A' : c - 'a';
            plaintext[i] = isupper(c) ? toupper(key[j]) : tolower(key[j]);
        }
    }

    // print cypher text
    printf("ciphertext: %s\n", plaintext);

    return 0;
}

bool only_alphas(string s) // alphabets checker
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool is_unique(string s)
{
    bool letters[26] = {false}; // define alphabets array
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        int index =
            isupper(s[i]) ? s[i] - 'A' : s[i] - 'a'; // index number 0 - 25 assigned to alphabets
        if (letters[index])
        {
            return false; // if letter has been counted will return false
        }
        letters[index] = true; // mark the letter TRUE indiciate has been seen
    }
    return true;
}
