#include <stdio.h>

// Function to calculate the GCD (Greatest Common Divisor) of two numbers
int calculateGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return calculateGCD(b, a % b);
    }
}

// Function to calculate the LCM (Least Common Multiple) of two numbers
int calculateLCM(int a, int b)
{
    int gcd = calculateGCD(a, b);
    int lcm = (a * b) / gcd;
    return lcm;
}

// Function to find GCD and LCM of two numbers
void findGCDandLCM(int a, int b, int *gcd, int *lcm)
{
    *gcd = calculateGCD(a, b);
    *lcm = calculateLCM(a, b);
}

int main()
{
    int num1, num2;

    // Input the two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    int gcd, lcm;

    // Call the findGCDandLCM function
    findGCDandLCM(num1, num2, &gcd, &lcm);

    // Print the GCD and LCM
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd);
    printf("LCM of %d and %d is: %d\n", num1, num2, lcm);

    return 0;
}
