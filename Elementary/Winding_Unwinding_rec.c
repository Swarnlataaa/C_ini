#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int n)
{
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1)
    {
        return 1;
    }

    // Recursive case: factorial of n is n multiplied by factorial of (n-1)
    return n * factorial(n - 1);
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Call the factorial function recursively
    int result = factorial(number);

    // Print the result
    printf("Factorial of %d is %d\n", number, result);

    return 0;
}
