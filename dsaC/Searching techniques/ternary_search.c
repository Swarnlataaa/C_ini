#include <stdio.h>

int ternarySearch(int arr[], int left, int right, int target)
{
    if (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target)
        {
            return mid1; // Element found at mid1
        }
        if (arr[mid2] == target)
        {
            return mid2; // Element found at mid2
        }

        if (target < arr[mid1])
        {
            return ternarySearch(arr, left, mid1 - 1, target); // Search left third
        }
        else if (target > arr[mid2])
        {
            return ternarySearch(arr, mid2 + 1, right, target); // Search right third
        }
        else
        {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target); // Search middle third
        }
    }

    return -1; // Element not found
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 16;

    int index = ternarySearch(arr, 0, n - 1, target);

    if (index != -1)
    {
        printf("Element %d found at index %d\n", target, index);
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
