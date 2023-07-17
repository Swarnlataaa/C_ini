#include <stdio.h>

// Recursive function to find the quotient of m divided by n
int findQuotient(int m, int n)
{
    if (m < n)
    {
        return 0; // Base case: m is less than n, quotient is 0
    }
    else
    {
        return 1 + findQuotient(m - n, n); // Recursive case: subtract n from m and increment quotient by 1
    }
}

int main()
{
    int m, n;

    printf("Enter two positive integers (m and n): ");
    scanf("%d %d", &m, &n);

    if (m > 0 && n > 0)
    {
        int quotient = findQuotient(m, n);
        printf("Quotient of %d divided by %d is %d\n", m, n, quotient);
    }
    else
    {
        printf("Both numbers must be positive integers.\n");
    }

    return 0;
}
