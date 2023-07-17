#include <stdio.h>

// Function to add two numbers and return the result
int addNumbers(int num1, int num2)
{
    return num1 + num2;
}

int main()
{
    int number1, number2, sum;

    // Input the two numbers
    printf("Enter first number: ");
    scanf("%d", &number1);
    printf("Enter second number: ");
    scanf("%d", &number2);

    // Call the addNumbers function and store the result in sum
    sum = addNumbers(number1, number2);

    // Print the sum
    printf("Sum: %d\n", sum);

    return 0;
}
