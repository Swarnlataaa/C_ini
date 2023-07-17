#include <stdio.h>

// Function to calculate the product of digits of a number
int calculateProductOfDigits(int number)
{
    int product = 1;

    // Calculate the product of digits
    while (number != 0)
    {
        int digit = number % 10;
        product *= digit;
        number /= 10;
    }

    return product;
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calculate the product of digits using the calculateProductOfDigits function
    int product = calculateProductOfDigits(number);

    // Print the product of digits
    printf("Product of digits: %d\n", product);

    return 0;
}
