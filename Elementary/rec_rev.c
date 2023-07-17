#include <stdio.h>

// Recursive function to reverse a number
int reverseNumber(int n)
{
    if (n < 10)
    {
        return n; // Base case: single digit number
    }
    else
    {
        int lastDigit = n % 10;
        int remainingDigits = n / 10;
        int reversed = reverseNumber(remainingDigits);
        int reversedNumber = (lastDigit * pow(10, (int)log10(remainingDigits) + 1)) + reversed;
        return reversedNumber;
    }
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    int reversed = reverseNumber(number);

    printf("Reversed number: %d\n", reversed);

    return 0;
}
