#include <stdio.h>

#define SIZE 5 // Size of the square matrix

void fillMatrix(int matrix[][SIZE])
{
    int i, j;

    // Fill the matrix with appropriate values
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (i < j)
            {
                matrix[i][j] = 1; // Upper right triangle
            }
            else if (i > j)
            {
                matrix[i][j] = -1; // Lower left triangle
            }
            else
            {
                matrix[i][j] = 0; // Diagonal
            }
        }
    }
}

void printMatrix(int matrix[][SIZE])
{
    int i, j;

    // Print the matrix
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matrix[SIZE][SIZE];

    fillMatrix(matrix);

    printf("Square Matrix:\n");
    printMatrix(matrix);

    return 0;
}
