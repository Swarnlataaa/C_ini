#include <stdio.h>

// Function to calculate the power of a number
int power(int n, int m)
{
    int result = 1;

    // Calculate the power
    for (int i = 1; i <= m; i++)
    {
        result *= n;
    }

    return result;
}

int main()
{
    int n, m;

    // Input the base number
    printf("Enter the base number: ");
    scanf("%d", &n);

    // Input the exponent
    printf("Enter the exponent: ");
    scanf("%d", &m);

    // Calculate the power using the power function
    int result = power(n, m);

    // Print the result
    printf("%d raised to the power %d = %d\n", n, m, result);

    return 0;
}
