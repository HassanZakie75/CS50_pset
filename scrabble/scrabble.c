// Simple scrable game between 2 players by Hassan Zakie
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// list of marks for each letter from the game scrabble

int calc_score(string word) // calculating score
{
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++) // scanning each char from the word input
    {
        char a = toupper(word[i]); // covert to capital letter
        if (isalpha(word[i]))      // alphebets comfirmation
        {
            score += POINTS[a - 'A'];
            ; // sum of score for each char
        }
    }
    return score;
}

int main(void)
{
    string word1 = get_string("Player 1: "); // player 1 input
    string word2 = get_string("Player 2: "); // player 2 input
    int score1 = calc_score(word1);
    int score2 = calc_score(word2);

    if (score1 > score2) // win or loose condition
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
