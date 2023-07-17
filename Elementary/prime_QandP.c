#include <stdio.h>

// Recursive function to check if a number is prime
int isPrime(int n, int i)
{
    if (n <= 2)
    {
        return (n == 2) ? 1 : 0;
    }

    if (n % i == 0)
    {
        return 0; // Not prime
    }

    if (i * i > n)
    {
        return 1; // Prime
    }

    return isPrime(n, i + 1);
}

// Recursive function to count prime numbers between p and q (inclusive)
int countPrimes(int p, int q)
{
    if (p > q)
    {
        return 0;
    }

    int count = isPrime(p, 2) + countPrimes(p + 1, q);
    return count;
}

int main()
{
    int p, q;

    printf("Enter the range (p and q): ");
    scanf("%d %d", &p, &q);

    int primeCount = countPrimes(p, q);

    printf("Total prime numbers between %d and %d (inclusive): %d\n", p, q, primeCount);

    return 0;
}
