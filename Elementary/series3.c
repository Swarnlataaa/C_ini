#include <stdio.h>
#include <math.h>

// Function to calculate the factorial of a number
double factorial(int number)
{
    double fact = 1.0;
    for (int i = 2; i <= number; i++)
    {
        fact *= i;
    }
    return fact;
}

// Function to evaluate the series sin(x)
double evaluateSinSeries(double x)
{
    double sinValue = x;
    double term = x;
    double epsilon = 1e-5; // Precision of five significant digits
    int sign = -1;
    int n = 3;

    while (fabs(term) >= epsilon)
    {
        term = pow(x, n) / factorial(n);
        sinValue += (sign * term);
        sign *= -1;
        n += 2;
    }

    return sinValue;
}

int main()
{
    double x;

    // Input the value of x
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Evaluate the sin(x) series using the evaluateSinSeries function
    double result = evaluateSinSeries(x);

    // Print the result
    printf("sin(%.2f) = %.5f\n", x, result);

    return 0;
}
