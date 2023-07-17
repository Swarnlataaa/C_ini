#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int number)
{
    int fact = 1;

    // Calculate the factorial
    for (int i = 1; i <= number; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is non-negative
    if (number >= 0)
    {
        // Calculate the factorial using the factorial function
        int fact = factorial(number);

        // Print the factorial
        printf("Factorial of %d: %d\n", number, fact);
    }
    else
    {
        printf("Invalid input! Factorial is not defined for negative numbers.\n");
    }

    return 0;
}
