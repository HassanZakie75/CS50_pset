// Readibility test using Coleman-Liau index by Hassan Zakie
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print Grade Level
    int grade_level = round(index);

    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int count_l = 0;
    for (int i = 0, n = strlen(text); i < n; i++) // loop to scan acrross the sentence
    {
        if (isalpha(text[i]) || isdigit(text[i]))
        {
            count_l++;
        }
    }
    return count_l;
}

int count_words(string text)
{
    // Return the number of words in text
    int count_w = 0;
    bool in_word = false;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) || isdigit(text[i]) || ispunct(text[i]))
        {
            if (!in_word)
            {
                count_w++;
                in_word = true;
            }
        }
        else
        {
            in_word = false;
        }
    }
    return count_w;
}

int count_sentences(string text)
{
    // Retrun the number of sentences in text
    int count_s = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_s++;
        }
    }
    return count_s;
}
