#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long calculateFactorial(int number)
{
    unsigned long long factorial = 1;
    for (int i = 1; i <= number; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is non-negative
    if (number < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        // Calculate and print the factorial
        unsigned long long factorial = calculateFactorial(number);
        printf("Factorial of %d: %llu\n", number, factorial);
    }

    return 0;
}
