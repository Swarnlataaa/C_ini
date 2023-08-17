#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void stoogeSort(int arr[], int left, int right)
{
    if (arr[left] > arr[right])
    {
        swap(&arr[left], &arr[right]);
    }

    if (right - left + 1 > 2)
    {
        int t = (right - left + 1) / 3;
        stoogeSort(arr, left, right - t);
        stoogeSort(arr, left + t, right);
        stoogeSort(arr, left, right - t);
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

    stoogeSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
