#include <stdio.h>

// Function to add two numbers and print the result
void addNumbers(int num1, int num2)
{
    int sum = num1 + num2;
    printf("Sum: %d\n", sum);
}

int main()
{
    int number1, number2;

    // Input the two numbers
    printf("Enter first number: ");
    scanf("%d", &number1);
    printf("Enter second number: ");
    scanf("%d", &number2);

    // Call the addNumbers function
    addNumbers(number1, number2);

    return 0;
}
