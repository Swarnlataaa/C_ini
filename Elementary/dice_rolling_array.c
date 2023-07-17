#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6

int rollDice()
{
    return rand() % SIDES + 1;
}

int main()
{
    int rolls;
    int diceCounts[SIDES] = {0}; // Initialize array to hold counts for each dice roll
    int i;

    srand(time(0)); // Seed the random number generator with the current time

    printf("Enter the number of rolls: ");
    scanf("%d", &rolls);

    // Perform the dice rolls and update the counts
    for (i = 0; i < rolls; i++)
    {
        int roll = rollDice();
        diceCounts[roll - 1]++;
    }

    // Print the results
    printf("Results:\n");
    for (i = 0; i < SIDES; i++)
    {
        printf("Dice %d: %d\n", i + 1, diceCounts[i]);
    }

    return 0;
}
