#include <stdio.h>

// Function to calculate the sum of digits of a number
int calculateDigitSum(int number)
{
    int sum = 0;
    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// Function to calculate the generic root of a number
int calculateGenericRoot(int number)
{
    while (number > 9)
    {
        number = calculateDigitSum(number);
    }
    return number;
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calculate the generic root
    int genericRoot = calculateGenericRoot(number);

    // Print the generic root
    printf("Generic Root of %d: %d\n", number, genericRoot);

    return 0;
}
