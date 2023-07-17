#include <stdio.h>

// Function to add two numbers and return the result
int addNumbers()
{
    int num1, num2, sum;

    // Input the two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calculate the sum
    sum = num1 + num2;

    return sum;
}

int main()
{
    int sum;

    // Call the addNumbers function and store the result in sum
    sum = addNumbers();

    // Print the sum
    printf("Sum: %d\n", sum);

    return 0;
}
