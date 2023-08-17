#include <stdio.h>
#include <stdbool.h>

#define N 8

bool isSafe(int board[N][N], int row, int col)
{
    // Check left side of the current row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int col)
{
    if (col >= N)
    {
        return true; // All queens are placed
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1; // Place the queen

            if (solveNQueensUtil(board, col + 1))
            {
                return true; // Recur to place rest of the queens
            }

            // If placing queen in the current position doesn't lead to a solution,
            // backtrack and try the next row
            board[i][col] = 0;
        }
    }

    return false; // No valid position found for this column
}

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

void solveNQueens()
{
    int board[N][N] = {0};

    if (solveNQueensUtil(board, 0))
    {
        printf("Solution:\n");
        printSolution(board);
    }
    else
    {
        printf("No solution exists.\n");
    }
}

int main()
{
    solveNQueens();
    return 0;
}
