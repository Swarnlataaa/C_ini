#include <stdio.h>

#define N 2 // Size of matrices

void strassenMatrixMultiply(int A[N][N], int B[N][N], int C[N][N])
{
    if (N == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int A11[N / 2][N / 2], A12[N / 2][N / 2], A21[N / 2][N / 2], A22[N / 2][N / 2];
    int B11[N / 2][N / 2], B12[N / 2][N / 2], B21[N / 2][N / 2], B22[N / 2][N / 2];
    int C11[N / 2][N / 2], C12[N / 2][N / 2], C21[N / 2][N / 2], C22[N / 2][N / 2];
    int M1[N / 2][N / 2], M2[N / 2][N / 2], M3[N / 2][N / 2], M4[N / 2][N / 2], M5[N / 2][N / 2], M6[N / 2][N / 2], M7[N / 2][N / 2];
    int temp1[N / 2][N / 2], temp2[N / 2][N / 2];

    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + N / 2];
            A21[i][j] = A[i + N / 2][j];
            A22[i][j] = A[i + N / 2][j + N / 2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + N / 2];
            B21[i][j] = B[i + N / 2][j];
            B22[i][j] = B[i + N / 2][j + N / 2];
        }
    }

    // Compute the seven products
    strassenMatrixMultiply(A11, B11, M1);
    strassenMatrixMultiply(A12, B21, M2);
    strassenMatrixMultiply(A11, B12, M3);
    strassenMatrixMultiply(A12, B22, M4);
    strassenMatrixMultiply(A21, B11, M5);
    strassenMatrixMultiply(A22, B21, M6);
    strassenMatrixMultiply(A21, B12, M7);

    // Calculate the four quadrants of the result matrix
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            temp1[i][j] = M1[i][j] + M2[i][j];
            temp2[i][j] = M3[i][j] + M4[i][j];
            C11[i][j] = temp1[i][j] + temp2[i][j];
            C12[i][j] = M1[i][j] + M2[i][j + N / 2];
            C21[i][j] = M3[i][j] + M4[i + N / 2][j];
            C22[i][j] = temp1[i][j] + M5[i][j] + M6[i][j] + M7[i][j];
        }
    }

    // Combine the four quadrants to get the final result matrix
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + N / 2] = C12[i][j];
            C[i + N / 2][j] = C21[i][j];
            C[i + N / 2][j + N / 2] = C22[i][j];
        }
    }
}

int main()
{
    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{5, 6}, {7, 8}};
    int C[N][N] = {{0, 0}, {0, 0}};

    strassenMatrixMultiply(A, B, C);

    printf("Matrix A:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("Matrix C (A * B):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
