#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to generate a random array
void generateRandomArray(int arr[], int size)
{
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the location of an item in the array
int findItemLocation(int arr[], int size, int item)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            return i; // Return the index where the item is found
        }
    }
    return -1; // Return -1 if item is not found
}

int main()
{
    int arr[SIZE];
    generateRandomArray(arr, SIZE);
    printArray(arr, SIZE);

    int item = 23;
    int location = findItemLocation(arr, SIZE, item);

    if (location == -1)
    {
        printf("Item %d not found in the array\n", item);
    }
    else
    {
        printf("Item %d found at index %d\n", item, location);
    }

    return 0;
}
