#include <stdio.h>
#include <conio.h>
void main()
{
    float a[2][2], b[2][2], c[2][2];
    int i, j;
    clrscr();
    printf("Enter the elements of 1st matrix\n");
    /* Reading two dimensional Array with the help of two for loop. If there is an array of 'n'
    dimension, 'n' numbers of loops are needed for inserting data to array.*/
    for (i = 0; i < 2; I++)
        for (j = 0; j < 2; j++)
        {
            scanf("%f", &a[i][j]);
        }
    printf("Enter the elements of 2nd matrix\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            scanf("%f", &b[i][j]);
        }
    /* accessing corresponding elements of two arrays. */
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j]; /* Sum of corresponding elements of two arrays. */
        }
    /* To display matrix sum in order. */
    printf("\nSum Of Matrix:");
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 2; ++j)
            printf("%f", c[i][j]);
        printf("\n");
    }
    getch();
}