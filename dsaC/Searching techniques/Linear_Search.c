#include <stdio.h>

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return index of the found element
        }
    }
    return -1; // Return -1 if element not found
}

int main()
{
    int arr[] = {12, 34, 56, 78, 90, 45, 67, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 45;

    int index = linearSearch(arr, n, target);

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
