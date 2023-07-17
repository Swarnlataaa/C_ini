#include <stdio.h>

// Function to check if a number is prime
int isPrime(int number)
{
    if (number <= 1)
    {
        return 0;
    }

    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

// Function to obtain the prime factors of a number
void getPrimeFactors(int number)
{
    printf("Prime factors of %d: ", number);

    // Check and print the prime factors
    for (int i = 2; i <= number; i++)
    {
        if (number % i == 0 && isPrime(i))
        {
            printf("%d ", i);
            number /= i;
            i--;
        }
    }

    printf("\n");
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Obtain the prime factors using the getPrimeFactors function
    getPrimeFactors(number);

    return 0;
}
