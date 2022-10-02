#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
int get_str_len(string name);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // name represents the name of a person who is being voted for
    // check whether this name actually exists within the candidates
    // if yes, add +1 to their vote count
    for(int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // FIRST SORT THEM
    bool sorted = false;
    int k = candidate_count;
    candidate temporary;
    while (k > 1 && !sorted)
    {
        sorted = true;
        for (int i = 0; i < candidate_count - 1; i++)
        {
            if (candidates[i+1].votes < candidates[i].votes)
            {
                sorted = false;
                temporary = candidates[i];
                candidates[i] = candidates[i+1];
                candidates[i+1] = temporary;
            }
        }
        k -= 1;
    }
    // In order to find how many people have won, we are going to get the biggest vote count;
    // Since the list is previously sorted, this is as simple as getting the last value

    int biggest_vote = candidates[candidate_count].votes;
    printf("%i GIHIHGIHGI", biggest_vote);

    for (int i = 0; i < candidate_count; i++){
        printf("%i", candidates[i].votes);
    }

    for (int i = 0; i< candidate_count; i++)
    {
        if (candidates[i].votes == biggest_vote)
        {
            for (int z = 0; z < get_str_len(candidates[i].name); z++)
            {
                printf("%c", candidates[i].name[z]);
            }
            printf(" is a winner with: %i votes. \n", candidates[i].votes);
        }
    }

}

int get_str_len(string name)
{
    int i = 0;
    while(name[i] != '\0')
    {
        i++;
    }
    return i;
}