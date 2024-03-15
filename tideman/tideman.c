#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
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
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; // unique pairs

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool checkcycle(int startingindex, int i);
int find_source(int n);
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
        candidates[i] = argv[i + 1]; // storing candidate's name
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

    // Query for votes, for number of voters,
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference. ranks[0] = charlie, ranks[1] = bob ....
        int ranks[candidate_count]; // initialise rank of length candidate count

        // Query for each rank, so rank 1, rank 2, rank 3 .. etc
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks)) // vote will record rank. j is the current rank number
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        // ranks should be completed for the 1 voter here
        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();

//printf("pairs unique %i\n",pair_count);

    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // given the name, we need to search the candidates[] for their index and add that into ranks[rank]
    bool found = false;
    int n = 0;

    while ((!found) && (n < candidate_count))
    {
        if (strcmp(name, candidates[n]) == 0)
        {
            found = true;
            ranks[rank] = n; // assign the candidate's index to the current rank
        }
        n++;
    }

    return found;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; (i + 1) < candidate_count; i++)
    {
        for (int j = (i + 1); j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] ++; // increase the value of i pointing to j
                                                                                    //            printf("%s beat %s\n",candidates[ranks[i]],candidates[ranks[j]]);
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // look through preferences and add into pairs
    // if preferences[i][j] != preferences[j][i] then add to pair (if not tied)

    for (int i = 0; (i + 1) < candidate_count; i++)
    {
        for (int j = (i + 1); j < candidate_count; j++)
        {
            if (preferences[i][j] != preferences[j][i]) // if this pair is not tied
            {
                int win;
                int lose;
                if (preferences[i][j] > preferences[j][i])
                {
                    win = i;
                    lose = j;
                }
                else
                {
                    win = j;
                    lose = i;
                }
                pairs[pair_count].winner = win;
                pairs[pair_count].loser = lose;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{   // sort from strongest link to least
    // bubble sort
    bool sorted = false;
    int i = 0;
    int n = pair_count;

    if (pair_count > 1) // only if more then 1 pair. or else its already 'sorted'
        while ((!sorted) && (n > 1))
        {
            for (int j = 0; j + 1 < n; j++)
            {
                // assume sorted
                sorted = true;

                // compare the strength of the j pair vs j + 1 pair
                int apair = preferences[pairs[j].winner][pairs[j].loser];
                int bpair = preferences[pairs[j + 1].winner][pairs[j + 1].loser];
                if ((apair) < (bpair))
                {
                    //swap them
                    pair tempa = pairs[j];
                    pair tempb = pairs[j + 1];

                    pairs[j] = tempb;
                    pairs[j + 1] = tempa;

                    sorted = false;
                }
            }
            n--;
        }

// test
/*

printf(" \n");
    for (int k = 0; k < pair_count; k++)
    {

        printf("%i -> %i \n", pairs[k].winner, pairs[k].loser);


    }
printf(" \n");


*/

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    bool cycle = false;
    // check if adding next entry creates cycle. if not, then lock it. use locked[i][j]
    for (int i = 0, n = pair_count; i < n; i++)
    {
                                                                          printf("pairs list = [%i][%i] \n", pairs[i].winner, pairs[i].loser);
        // check if adding pairs[i] creates cycle
        int startingindex = pairs[i].winner;
        int nextindex = pairs[i].loser;

        cycle = checkcycle(startingindex, nextindex);

        if (!cycle) // entry of pairs[i] does not create cycle
        {
            // add
            locked[pairs[i].winner][pairs[i].loser] = true;
                                                                            printf("locked[%i][%i] = true\n", pairs[i].winner, pairs[i].loser);
        }
    }


    return;
}

bool checkcycle(int startingindex, int i) //recursive
{
    bool cycle = false;
    int j = 0;


    while ((!cycle) && (j < candidate_count))
    {
        printf("checking startingindex %i against %i\n", startingindex, j);
        if (locked[i][j] == true) // check locked list if any locked[i][*] == true, else no cycle
        {
             if (j == startingindex)
             {
                cycle = true;
             }
             else
             {
                cycle = checkcycle(startingindex, j);
             }
        }
        j++;
    }

    return cycle;
}

int find_source(int n)
{ // pick true sorted pair, goto winner, search for loser. if found, do again. else its the winner
    int i = 0;
    int retval = -1;

                                                                                                    //    printf("n is %i\n",n);

    while ((retval < 0) && (i < pair_count))
    {
        if ((locked[i][n]))
        {
            retval = find_source(i);
        }
        i++;
    }
    // if searched the list and no more source
    if (retval == -1)
    {
        retval = n;
    }
    return retval;
}

// Print the winner of the election
void print_winner(void)
{
    // pick first locked true sorted pair, goto winner, serch for loser. if found,do again. else its the winner
    int index = find_source(pairs[0].winner);
//    printf("%i\n", index);
    printf("%s\n", candidates[index]);

    return;
}
