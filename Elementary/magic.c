#include <stdio.h>

// Function to check if a number is a magic number
int isMagicNumber(int number)
{
    int sum = 0;

    // Calculate the sum of the digits
    while (number > 0 || sum > 9)
    {
        if (number == 0)
        {
            number = sum;
            sum = 0;
        }
        sum += number % 10;
        number /= 10;
    }

    // Check if the sum is 1
    return (sum == 1);
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is a magic number
    if (isMagicNumber(number))
    {
        printf("%d is a magic number.\n", number);
    }
    else
    {
        printf("%d is not a magic number.\n", number);
    }

    return 0;
}
