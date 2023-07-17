#include <stdio.h>
#include <math.h>

#define SIZE 5 // Size of the array

double calculateSum(int array[], int size)
{
    int i;
    double sum = 0;

    for (i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

double calculateMean(int array[], int size)
{
    double sum = calculateSum(array, size);
    return sum / size;
}

double calculateVariance(int array[], int size)
{
    double mean = calculateMean(array, size);
    double variance = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        variance += pow(array[i] - mean, 2);
    }

    return variance / size;
}

double calculateStandardDeviation(int array[], int size)
{
    double variance = calculateVariance(array, size);
    return sqrt(variance);
}

int main()
{
    int array[] = {1, 2, 3, 4, 5}; // Example array
    int size = sizeof(array) / sizeof(array[0]);
    double sum, mean, variance, stdDeviation;

    sum = calculateSum(array, size);
    mean = calculateMean(array, size);
    variance = calculateVariance(array, size);
    stdDeviation = calculateStandardDeviation(array, size);

    printf("Sum: %.2f\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stdDeviation);

    return 0;
}
