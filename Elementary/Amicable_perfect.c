#include <stdio.h>

// Function to calculate the sum of proper divisors of a number
int calculateSumOfDivisors(int number)
{
    int sum = 0;
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

// Function to print amicable pairs and perfect numbers within a range
void printAmicablePairsAndPerfectNumbers(int start, int end)
{
    printf("Amicable pairs:\n");
    for (int i = start; i <= end; i++)
    {
        int sumOfDivisorsA = calculateSumOfDivisors(i);
        int sumOfDivisorsB = calculateSumOfDivisors(sumOfDivisorsA);

        if (i == sumOfDivisorsB && i != sumOfDivisorsA)
        {
            printf("(%d, %d)\n", i, sumOfDivisorsA);
        }
    }

    printf("\nPerfect numbers:\n");
    for (int i = start; i <= end; i++)
    {
        int sumOfDivisors = calculateSumOfDivisors(i);

        if (i == sumOfDivisors)
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    int start, end;

    // Input the range
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Print amicable pairs and perfect numbers using the printAmicablePairsAndPerfectNumbers function
    printAmicablePairsAndPerfectNumbers(start, end);

    return 0;
}
