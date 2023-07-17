#include <stdio.h>

#define SIZE 2 // Size of each dimension of the array

void readArray(int array[][SIZE][SIZE])
{
    int i, j, k;

    printf("Enter the elements of the array:\n");

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                printf("Enter the value at index [%d][%d][%d]: ", i, j, k);
                scanf("%d", &array[i][j][k]);
            }
        }
    }
}

void displayArray(int array[][SIZE][SIZE])
{
    int i, j, k;

    printf("Array elements:\n");

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                printf("%d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main()
{
    int array[SIZE][SIZE][SIZE];

    readArray(array);

    printf("\n");

    displayArray(array);

    return 0;
}
