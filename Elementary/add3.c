#include <stdio.h>

// Function to add two numbers and print the result
void addNumbers()
{
    int num1, num2, sum;

    // Input the two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calculate the sum
    sum = num1 + num2;

    // Print the sum
    printf("Sum: %d\n", sum);
}

int main()
{
    // Call the addNumbers function
    addNumbers();

    return 0;
}
