#include <stdio.h>

// Recursive function to find the remainder of m divided by n
int findRemainder(int m, int n)
{
    if (m < n)
    {
        return m; // Base case: m is less than n, remainder is m
    }
    else
    {
        return findRemainder(m - n, n); // Recursive case: subtract n from m and find remainder
    }
}

int main()
{
    int m, n;

    printf("Enter two positive integers (m and n): ");
    scanf("%d %d", &m, &n);

    if (m > 0 && n > 0)
    {
        int remainder = findRemainder(m, n);
        printf("Remainder of %d divided by %d is %d\n", m, n, remainder);
    }
    else
    {
        printf("Both numbers must be positive integers.\n");
    }

    return 0;
}
