#include <stdio.h>

// Non-tail recursive function to calculate the sum of positive integers from 1 to n
int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        int result = n + sum(n - 1); // Recursive call is not the last operation
        return result;
    }
}

int main()
{
    int number;

    // Input the number
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Call the sum function
    int result = sum(number);

    // Print the result
    printf("Sum of positive integers from 1 to %d is %d\n", number, result);

    return 0;
}
