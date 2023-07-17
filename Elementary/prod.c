#include <stdio.h>

// Function to calculate the product of a float and an int
float calculateProduct(float num1, int num2)
{
    float product = num1 * num2;
    return product;
}

int main()
{
    float floatValue;
    int intValue;

    // Input the float and int values
    printf("Enter a float value: ");
    scanf("%f", &floatValue);
    printf("Enter an integer value: ");
    scanf("%d", &intValue);

    // Call the calculateProduct function and store the result in a variable
    float result = calculateProduct(floatValue, intValue);

    // Print the result
    printf("Product: %.2f\n", result);

    return 0;
}
