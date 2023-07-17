#include <stdio.h>

#define SIZE 10

void printHistogram(int array[], int size)
{
    int i, j;

    // Find the maximum value in the array
    int max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    // Print the histogram
    for (i = max; i > 0; i--)
    {
        for (j = 0; j < size; j++)
        {
            if (array[j] >= i)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Print the x-axis labels
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[SIZE] = {3, 5, 1, 7, 2, 4, 6, 9, 8, 3}; // Example array

    printf("Histogram:\n");
    printHistogram(array, SIZE);

    return 0;
}
