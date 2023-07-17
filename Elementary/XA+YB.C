#include <stdio.h>

#define ROWS 2
#define COLS 2

void matrixMultiplication(int A[][COLS], int B[][COLS], int result[][COLS], int rows, int cols)
{
    int i, j, k;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = 0;

            for (k = 0; k < cols; k++)
            {
                result[i][j] += (2 * A[i][k]) + (3 * B[k][j]);
            }
        }
    }
}

void displayMatrix(int matrix[][COLS], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[ROWS][COLS] = {{1, 2}, {3, 4}};
    int B[ROWS][COLS] = {{5, 6}, {7, 8}};
    int result[ROWS][COLS];

    matrixMultiplication(A, B, result, ROWS, COLS);

    printf("Resultant matrix:\n");
    displayMatrix(result, ROWS, COLS);

    return 0;
}
