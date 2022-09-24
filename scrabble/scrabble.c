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

    printf("%i", score1);
    printf("%i", score2);

    // TODO: Print the winner
}

int compute_score(string word)
{

    int word_length = 0;
    int score = 0;

    while (word[word_length] != '\0'){
        word_length++;
    }

    for (int i = 0; i < word_length; i++){
        // Checks whether there are any special characters and ignores them
        if((int)word[i] < 64 || (int)word[i] > 90){
            continue;
        }

        // 'D' - 'A' = D points 68 - 64 4 ( minus 1)

        score += POINTS[(int)word[i] - 65];

    }
    return score;
    // 64 - A
    // 90 - Z

}
