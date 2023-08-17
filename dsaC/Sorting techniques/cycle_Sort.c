#include <stdio.h>

void cycleSort(int arr[], int n)
{
    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++)
    {
        int item = arr[cycleStart];
        int pos = cycleStart;

        for (int i = cycleStart + 1; i < n; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }

        if (pos == cycleStart)
        {
            continue;
        }

        while (item == arr[pos])
        {
            pos++;
        }

        if (pos != cycleStart)
        {
            int temp = item;
            item = arr[pos];
            arr[pos] = temp;
        }

        while (pos != cycleStart)
        {
            pos = cycleStart;

            for (int i = cycleStart + 1; i < n; i++)
            {
                if (arr[i] < item)
                {
                    pos++;
                }
            }

            while (item == arr[pos])
            {
                pos++;
            }

            if (item != arr[pos])
            {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
            }
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

    cycleSort(arr, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
