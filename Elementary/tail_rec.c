#include <stdio.h>

// Tail recursive function to calculate the sum of positive integers from 1 to n
int sum(int n, int currentSum)
{
    if (n == 0)
    {
        return currentSum;
    }
    else
    {
        return sum(n - 1, currentSum + n); // Recursive call is the last operation
    }
}

int main()
{
    int number;

    // Input the number
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Call the sum function
    int result = sum(number, 0);

    // Print the result
    printf("Sum of positive integers from 1 to %d is %d\n", number, result);

    return 0;
}
