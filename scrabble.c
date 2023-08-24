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
    //Choosing the winner according to the scores
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    //Declaring variable for the score
    int score = 0;
    //Loop that goes over the word
    for (int i = 0; word[i] != '\0' ; i++)
    {
        char letter = toupper(word[i]); //putting every single letter in uppercase

        if (letter >= 'A' && letter <= 'Z')
        {
            score += POINTS[letter - 'A']; //adding the score according the points of the letter
        }
    }

    return score; //returning the score
}