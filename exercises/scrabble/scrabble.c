#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else
    {
        if (score1 < score2)
        {
            printf("Player 2 Wins!\n");
        }
        else
        {
            printf("Tie!\n");
        }
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int i = 0;
    int total = 0;
    int points;
    int binary = word[0];

    while (binary != 0)
    {
        if (binary < 65 || binary > 122 || (binary > 90 && binary < 97))
        {
            points = 0;
        }
        else
        {
            if (isupper(word[i]))
            {
                binary = binary - 65;
                points = POINTS[binary];
            }
            else
            {
                binary = binary - 97;
                points = POINTS[binary];
            }

        }

        total = total + points;

        i++;

        binary = word[i];
    }

    return(total);
}
