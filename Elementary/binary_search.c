#include <stdio.h>

int binarySearch(int array[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (array[mid] == target)
        {
            return mid; // Found the target, return the index
        }
        else if (array[mid] < target)
        {
            low = mid + 1; // Target is in the right half
        }
        else
        {
            high = mid - 1; // Target is in the left half
        }
    }

    return -1; // Target not found
}

int main()
{
    int array[] = {1, 3, 5, 7, 9, 11, 13}; // Example sorted array
    int size = sizeof(array) / sizeof(array[0]);
    int target;

    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = binarySearch(array, size, target);

    if (result != -1)
    {
        printf("Target found at index %d\n", result);
    }
    else
    {
        printf("Target not found\n");
    }

    return 0;
}
