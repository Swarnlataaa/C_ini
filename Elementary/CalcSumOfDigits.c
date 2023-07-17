#include <stdio.h>

// Function to calculate the sum of digits of a number
int calculateSumOfDigits(int number)
{
    int sum = 0;

    // Calculate the sum of digits
    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calculate the sum of digits using the calculateSumOfDigits function
    int sum = calculateSumOfDigits(number);

    // Print the sum of digits
    printf("Sum of digits: %d\n", sum);

    return 0;
}
