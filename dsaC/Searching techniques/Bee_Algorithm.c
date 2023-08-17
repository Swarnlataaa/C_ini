#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_BEES 50
#define NUM_EMPLOYED_BEES 30
#define NUM_ONLOOKER_BEES (NUM_BEES - NUM_EMPLOYED_BEES)
#define MAX_ITERATIONS 1000
#define LOWER_BOUND -10.0
#define UPPER_BOUND 10.0

typedef struct
{
    double position;
    double fitness;
} Bee;

double quadraticFunction(double x)
{
    return x * x;
}

void initializeBees(Bee bees[], int num_bees)
{
    for (int i = 0; i < num_bees; i++)
    {
        bees[i].position = LOWER_BOUND + (double)rand() / RAND_MAX * (UPPER_BOUND - LOWER_BOUND);
        bees[i].fitness = quadraticFunction(bees[i].position);
    }
}

double evaluateFitness(double position)
{
    return quadraticFunction(position);
}

void employedBeesPhase(Bee bees[])
{
    for (int i = 0; i < NUM_EMPLOYED_BEES; i++)
    {
        int j = rand() % NUM_EMPLOYED_BEES;
        double newPosition = bees[i].position + ((double)rand() / RAND_MAX - 0.5);

        if (newPosition < LOWER_BOUND)
        {
            newPosition = LOWER_BOUND;
        }
        else if (newPosition > UPPER_BOUND)
        {
            newPosition = UPPER_BOUND;
        }

        double newFitness = evaluateFitness(newPosition);

        if (newFitness < bees[i].fitness)
        {
            bees[i].position = newPosition;
            bees[i].fitness = newFitness;
        }
    }
}

int compareBees(const void *a, const void *b)
{
    return ((Bee *)a)->fitness - ((Bee *)b)->fitness;
}

void onlookerBeesPhase(Bee bees[])
{
    qsort(bees, NUM_EMPLOYED_BEES, sizeof(Bee), compareBees);

    double fitnessSum = 0.0;
    for (int i = 0; i < NUM_EMPLOYED_BEES; i++)
    {
        fitnessSum += 1.0 / bees[i].fitness;
    }

    for (int i = 0; i < NUM_ONLOOKER_BEES; i++)
    {
        double selectionProb = ((double)rand() / RAND_MAX) * fitnessSum;
        int j = 0;
        double partialSum = 1.0 / bees[0].fitness;

        while (partialSum < selectionProb)
        {
            j++;
            partialSum += 1.0 / bees[j].fitness;
        }

        double newPosition = bees[j].position + ((double)rand() / RAND_MAX - 0.5);

        if (newPosition < LOWER_BOUND)
        {
            newPosition = LOWER_BOUND;
        }
        else if (newPosition > UPPER_BOUND)
        {
            newPosition = UPPER_BOUND;
        }

        double newFitness = evaluateFitness(newPosition);

        if (newFitness < bees[j].fitness)
        {
            bees[j].position = newPosition;
            bees[j].fitness = newFitness;
        }
    }
}

int main()
{
    srand(time(NULL));

    Bee bees[NUM_BEES];

    initializeBees(bees, NUM_BEES);

    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++)
    {
        employedBeesPhase(bees);
        onlookerBeesPhase(bees);
    }

    // Find the best bee (minimized fitness)
    int bestBeeIndex = 0;
    for (int i = 1; i < NUM_BEES; i++)
    {
        if (bees[i].fitness < bees[bestBeeIndex].fitness)
        {
            bestBeeIndex = i;
        }
    }

    printf("Optimal solution: %.6f\n", bees[bestBeeIndex].position);
    printf("Minimum value: %.6f\n", bees[bestBeeIndex].fitness);

    return 0;
}
