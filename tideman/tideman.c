#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    // if name is a valid candidate name -> update ranks array that the voter
    // has the candidate as their rank preference 0 is first preference, 1 is second, etc

    // ranks[i] represents the user's i-th preference
    // return true if rank is stored succesfully

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            // i (0) == Alice so i-th index is alice
            ranks[rank] = i; // Set the user's rank preference as the index of the person they are voting for
            return true; // success
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    //preferences
    //preferences[i][j] represents number of voters who prefer candidate i over candidate j
    //ranks[] holds a user's preferences
    // preferences[ranks[i=0][j=1]]

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i != j)
            {
                preferences[ranks[i]][ranks[j]] += 1;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int pair = 0; pair < candidate_count; pair++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                if (i != j)
                {
                    if (preferences[i][j] == preferences[j][i])
                    {
                        continue;
                    }
                    if (preferences[i][j] > preferences[j][i])
                    {
                        pairs[pair].winner = j;
                        pairs[pair].loser = i;
                        pair_count++;
                        continue;
                    }
                    pairs[pair].winner = i;
                    pairs[pair].loser = j;
                    pair_count++;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Bubble sort
    int k = pair_count - 1;
    pair temporary;
    bool is_sorted = false;

    while (k > 1 && !is_sorted)
    {
        is_sorted = true;
        for (int pair = k; pair > 0; pair--)
        {
            printf("WTF");
            if (pairs[pair].winner > pairs[pair - 1].winner)
            {
                is_sorted = false;
                temporary = pairs[pair - 1];
                pairs[pair - 1] = pairs[pair];
                pairs[pair] = temporary;
            }
        }
        k--;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        printf("%i is aihiahwih", pairs[i].winner);
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // for (int k = 0; k < pair_count - 1; k++)
    // {
    //     for (int j)
    // }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}