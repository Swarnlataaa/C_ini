#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is perfect
bool isPerfectNumber(int number)
{
    int sum = 0;

    // Calculate the sum of proper divisors
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }

    // Check if the sum of proper divisors is equal to the number
    return sum == number;
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is perfect
    if (isPerfectNumber(number))
    {
        printf("%d is a perfect number.\n", number);
    }
    else
    {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}
