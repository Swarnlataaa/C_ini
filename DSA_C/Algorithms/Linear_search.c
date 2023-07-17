#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int main()
{
    int arr[] = {5, 2, 9, 1, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 7;
    int result = linearSearch(arr, n, target);

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
