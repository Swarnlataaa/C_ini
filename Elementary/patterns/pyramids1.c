#include <stdio.h>

// Recursive function to print a pyramid of stars
void printPyramid(int n, int currentRow, int spaces)
{
    // Base case: When currentRow is greater than n, stop recursion
    if (currentRow > n)
    {
        return;
    }

    int i;

    // Print spaces
    for (i = 1; i <= spaces; i++)
    {
        printf(" ");
    }

    // Print stars
    for (i = 1; i <= currentRow; i++)
    {
        printf("* ");
    }

    printf("\n");

    // Recursive call for the next row
    printPyramid(n, currentRow + 1, spaces - 1);
}

int main()
{
    int height;

    printf("Enter the height of the pyramid: ");
    scanf("%d", &height);

    if (height >= 0)
    {
        printf("Pyramid:\n");
        printPyramid(height, 1, height - 1);
    }
    else
    {
        printf("Height must be a non-negative integer.\n");
    }

    return 0;
}
