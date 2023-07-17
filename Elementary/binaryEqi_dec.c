#include <stdio.h>

// Recursive function to calculate the binary equivalent of a decimal number
void decimalToBinary(int n)
{
    if (n > 0)
    {
        decimalToBinary(n / 2); // Recursive call to divide the number by 2
        printf("%d", n % 2);    // Print the remainder (binary digit)
    }
}

int main()
{
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if (decimal >= 0)
    {
        printf("Binary equivalent of %d is ", decimal);
        decimalToBinary(decimal);
        printf("\n");
    }
    else
    {
        printf("Decimal number must be non-negative.\n");
    }

    return 0;
}
