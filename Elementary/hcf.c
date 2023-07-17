#include <stdio.h>

// Function to calculate the HCF of two numbers
int calculateHCF(int number1, int number2)
{
    int remainder;

    // Euclidean algorithm to calculate HCF
    while (number2 != 0)
    {
        remainder = number1 % number2;
        number1 = number2;
        number2 = remainder;
    }

    return number1;
}

int main()
{
    int number1, number2;

    // Input the numbers
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);

    // Calculate and print the HCF
    int hcf = calculateHCF(number1, number2);
    printf("HCF of %d and %d is %d.\n", number1, number2, hcf);

    return 0;
}
