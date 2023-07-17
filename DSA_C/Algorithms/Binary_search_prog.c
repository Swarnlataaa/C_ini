#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid; // Return the index where the target is found
        }
        else if (arr[mid] < target)
        {
            low = mid + 1; // Target is in the right half
        }
        else
        {
            high = mid - 1; // Target is in the left half
        }
    }
    return -1; // Return -1 if target is not found
}

int main()
{
    int arr[] = {1, 2, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 7;
    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
    {
        printf("Element %d not found in the array\n", target);
    }
    else
    {
        printf("Element %d found at index %d\n", target, result);
    }

    return 0;
}
