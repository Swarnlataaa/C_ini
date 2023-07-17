#include <stdio.h>
#include <conio.h>
int main()
{
    int i, j, k;
    int row1, col1, row2, col2, row3, col3;
    int mat1[5][5], mat2[5][5], mat3[5][5];
    clrscr();
    printf(“\n enter the number of rows in the first matrix
           :”);
    scanf(“% d”, &row1);
    printf(“\n enter the number of columns in the first matrix
           :”);
    scanf(“% d”, &col1);
    printf(“\n enter the number of rows in the second matrix
           :”);
    scanf(“% d”, &row2);
    printf(“\n enter the number of columns in the second matrix
           :”);
    scanf(“% d”, &col2);
    if (col1 != row2)
    {
        printf(“\n The number of columns in the first matrix must be equal to the number of rows
                in the second matrix ”);
        getch();
        exit();
    }
    row3 = row1;
    col3 = col3;
    printf(“\n Enter the elements of the first matrix”);
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
            scanf(“% d”, &mat1[i][j]);
    }

    printf(“\n Enter the elements of the second matrix”);
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
            scanf(“% d”, &mat2[i][j]);
    }
    for (i = 0; i < row3; i++)
    {
        for (j = 0; j < col3; j++)
        {
            mat3[i][j] = 0;
            for (k = 0; k < col3; k++)
                mat3[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    printf(“\n The elements of the product matrix are”) : for (i = 0; i < row3; i++)
    {
        printf(“\n”);
        for (j = 0; j < col3; j++)
            printf(“\t % d”, mat3[i][j]);
    }
    return 0;
}