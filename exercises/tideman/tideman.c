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
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i+1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] ++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i+1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pair pair_results = {i, j};
                pairs[pair_count] = pair_results;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pair pair_results = {j, i};
                pairs[pair_count] = pair_results;
            }
            pair_count++;
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count+1; i++)
    {
        int strength = preferences[pairs[i].winner][pairs[i].loser];

        for (int j = i+1; j < pair_count+1; j++)
        {
            int comparison = preferences[pairs[j].winner][pairs[j].loser];
            if (strength < comparison)
            {
                pair temp_pairs = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp_pairs;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    printf("Locking pairs... \n");
    int eliminated[candidate_count];

    for (int j = 0; j < candidate_count; j++)
    {
        eliminated[j] = 0;
    }

    for (int i = 0; i < pair_count+1; i++)
    {
        int total = 0;
        for (int o = 0; o < candidate_count; o++)
        {
            total = total + eliminated[o];

            if (total > candidate_count-2)
            {
                for (int p = 0; p < candidate_count; p++)
                {
                    if (eliminated[p] == 0)
                    {
                        printf("attempting to print \n");
                        printf("winner = %s \n", candidates[p]);
                    }
                }
                return;
            }

        locked[pairs[i].winner][pairs[i].loser] = true;
        eliminated[pairs[i].loser] = 1;
        printf("loser: %s \n", candidates[pairs[i].loser]);
        }


    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
}