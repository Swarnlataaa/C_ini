#include <stdio.h>

// Function to calculate the binary equivalent of a decimal number
void calculateBinary(int number)
{
    int binary[32];
    int i = 0;

    // Calculate the binary equivalent
    while (number > 0)
    {
        binary[i] = number % 2;
        number /= 2;
        i++;
    }

    // Print the binary equivalent in reverse order
    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main()
{
    int decimalNumber;

    // Input the decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Call the calculateBinary function
    calculateBinary(decimalNumber);

    return 0;
}
