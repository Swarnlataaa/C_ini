#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int number)
{
    if (number <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Prime numbers up to %d:\n", number);

    // Check and print prime numbers up to the input number
    for (int i = 2; i <= number; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
