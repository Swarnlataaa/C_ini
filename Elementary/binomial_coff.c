#include <stdio.h>

// Recursive function to calculate the binomial coefficient C(n, k)
int binomialCoefficient(int n, int k)
{
    // Base cases
    if (k == 0 || k == n)
    {
        return 1;
    }

    // Recursive cases
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int main()
{
    int n, k;

    printf("Enter the values of n and k: ");
    scanf("%d %d", &n, &k);

    if (n >= k && n >= 0 && k >= 0)
    {
        int coefficient = binomialCoefficient(n, k);
        printf("C(%d, %d) = %d\n", n, k, coefficient);
    }
    else
    {
        printf("Invalid input. Please make sure n >= k >= 0.\n");
    }

    return 0;
}
