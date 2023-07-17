#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void interchangeLargestAndSmallest(int array[], int size)
{
    int i;
    int maxIndex = 0;
    int minIndex = 0;

    // Find the index of the largest and smallest elements
    for (i = 1; i < size; i++)
    {
        if (array[i] > array[maxIndex])
        {
            maxIndex = i;
        }
        if (array[i] < array[minIndex])
        {
            minIndex = i;
        }
    }

    // Swap the largest and smallest elements
    swap(&array[maxIndex], &array[minIndex]);
}

int main()
{
    int array[] = {5, 8, 2, 1, 6}; // Example array
    int size = sizeof(array) / sizeof(array[0]);
    int i;

    printf("Original array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    interchangeLargestAndSmallest(array, size);

    printf("Array after interchange: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
