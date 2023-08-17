#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isSorted(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

void shuffle(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void bogoSort(int arr[], int size)
{
    srand(time(NULL));
    int iterations = 0;

    while (!isSorted(arr, size))
    {
        shuffle(arr, size);
        iterations++;
    }

    printf("Sorted array after %d iterations:\n", iterations);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bogoSort(arr, size);

    return 0;
}
