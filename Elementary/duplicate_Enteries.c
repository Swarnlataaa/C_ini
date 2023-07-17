#include <stdio.h>

#define SIZE 10 // Size of the array

int countDuplicates(int array[], int size)
{
    int count = 0;
    int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                count++;
                break;
            }
        }
    }

    return count;
}

int main()
{
    int array[] = {2, 3, 4, 2, 5, 6, 3, 8, 4, 9}; // Example array
    int size = sizeof(array) / sizeof(array[0]);
    int duplicateCount;

    duplicateCount = countDuplicates(array, size);

    printf("Number of duplicate entries: %d\n", duplicateCount);

    return 0;
}
