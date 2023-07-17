#include <stdio.h>
int main()
{
    int row, c, n, I, temp;
    printf("Enter the number of rows in pyramid of stars you wish to see ");
    scanf("%d", &n);
    temp = n;
    for (row = 1; row <= n; row++)
    {
        for (i = 1; i < temp; i++)
        {
            printf(" ");
            temp--;
            for (c = 1; c <= 2 * row - 1; c++)
            {
                printf("*");
                printf("\n");
            }
        }
    }
    return 0;
}