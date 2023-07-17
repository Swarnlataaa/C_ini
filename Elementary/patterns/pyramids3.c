#include <stdio.h>

// Recursive function to print the pyramid pattern
void printPyramid(int n)
{
    // Base case: When n is less than 1, stop recursion
    if (n < 1)
    {
        return;
    }

    int i;

    // Print characters
    for (i = 1; i <= n; i++)
    {
        printf("%c ", 'a' + i - 1);
    }

    printf("\n");

    // Recursive call for the next row
    printPyramid(n - 1);
}

int main()
{
    int height;

    printf("Enter the height of the pyramid: ");
    scanf("%d", &height);

    if (height >= 0)
    {
        printf("Pyramid:\n");
        printPyramid(height);
    }
    else
    {
        printf("Height must be a non-negative integer.\n");
    }

    return 0;
}
