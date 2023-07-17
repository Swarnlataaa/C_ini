#include <stdio.h>
#include <math.h>

// Function to calculate the sum, average, and standard deviation of an array of integers
void calculateStats(int numbers[], int size, int *sum, float *average, float *stdDev)
{
    // Calculate the sum
    *sum = 0;
    for (int i = 0; i < size; i++)
    {
        *sum += numbers[i];
    }

    // Calculate the average
    *average = (float)*sum / size;

    // Calculate the standard deviation
    float sumOfSquares = 0;
    for (int i = 0; i < size; i++)
    {
        sumOfSquares += pow(numbers[i] - *average, 2);
    }
    *stdDev = sqrt(sumOfSquares / size);
}

int main()
{
    int size;
    printf("Enter the number of integers: ");
    scanf("%d", &size);

    int numbers[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int sum;
    float average, stdDev;

    // Call the calculateStats function and pass the array, size, and pointers to the variables
    calculateStats(numbers, size, &sum, &average, &stdDev);

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Standard Deviation: %.2f\n", stdDev);

    return 0;
}
