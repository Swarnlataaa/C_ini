#include <stdio.h>

// Function to print the multiplication table of a number
void printMultiplicationTable(int number)
{
    printf("Multiplication Table of %d:\n", number);

    // Print the multiplication table
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", number, i, number * i);
    }
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Call the printMultiplicationTable function
    printMultiplicationTable(number);

    return 0;
}
