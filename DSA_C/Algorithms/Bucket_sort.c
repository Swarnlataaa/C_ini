#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform insertion sort on each bucket
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n, int numBuckets)
{
    // Create numBuckets empty buckets
    int **buckets = (int **)malloc(numBuckets * sizeof(int *));
    for (int i = 0; i < numBuckets; i++)
    {
        buckets[i] = NULL;
    }

    // Determine the range of each bucket
    int maxVal = findMax(arr, n);
    int range = (maxVal + 1) / numBuckets;

    // Distribute the elements into buckets
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / range;
        if (buckets[bucketIndex] == NULL)
        {
            buckets[bucketIndex] = (int *)malloc(n * sizeof(int));
            buckets[bucketIndex][0] = arr[i];
            buckets[bucketIndex][1] = 1;
        }
        else
        {
            int j = buckets[bucketIndex][1]++;
            buckets[bucketIndex][j] = arr[i];
        }
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < numBuckets; i++)
    {
        if (buckets[i] != NULL)
        {
            insertionSort(buckets[i], buckets[i][1]);
        }
    }

    // Merge the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < numBuckets; i++)
    {
        if (buckets[i] != NULL)
        {
            for (int j = 0; j < buckets[i][1]; j++)
            {
                arr[index++] = buckets[i][j];
            }
            free(buckets[i]);
        }
    }

    // Free the memory allocated for the buckets
    free(buckets);
}

// Function to print the array
void printArray(int arr[], int n)
{
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {29, 15, 38, 9, 23, 50, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int numBuckets = 3;

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n, numBuckets);
    printArray(arr, n);

    return 0;
}
