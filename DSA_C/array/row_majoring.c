#include <stdio.h>

#define ROWS 3
#define COLS 4

int main()
{
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // Access and print the values of the 2D array using row-major ordering
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int index = i * COLS + j;
            printf("Element at index %d: %d\n", index, matrix[i][j]);
        }
    }

    return 0;
}
