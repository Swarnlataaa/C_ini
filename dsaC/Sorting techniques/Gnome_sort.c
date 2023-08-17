#include <stdio.h>

void gnomeSort(int arr[], int size)
{
    int i = 0;

    while (i < size)
    {
        if (i == 0 || arr[i] >= arr[i - 1])
        {
            i++;
        }
        else
        {
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;

            i--;
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    gnomeSort(arr, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
