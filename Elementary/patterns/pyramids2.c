#include <stdio.h>

// Recursive function to print the pyramid pattern
void printPyramid(int n, int currentRow)
{
    // Base case: When currentRow is greater than n, stop recursion
    if (currentRow > n)
    {
        return;
    }

    int i;

    // Print numbers
    for (i = 1; i <= currentRow; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    // Recursive call for the next row
    printPyramid(n, currentRow + 1);
}

int main()
{
    int height;

    printf("Enter the height of the pyramid: ");
    scanf("%d", &height);

    if (height >= 0)
    {
        printf("Pyramid:\n");
        printPyramid(height, 1);
    }
    else
    {
        printf("Height must be a non-negative integer.\n");
    }

    return 0;
}
