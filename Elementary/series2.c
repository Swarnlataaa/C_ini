#include <stdio.h>

// Function to calculate the sum of the series S = 1/1! + 1/2! + 1/3! + ... + 1/n!
double calculateSeriesS()
{
    double sum = 0.0;
    double term = 1.0;
    int n;
    printf("Enter the value of n for series S: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        term /= i;
        sum += term;
    }
    return sum;
}

// Function to calculate the sum of the series S = 1 + 1/3! + 1/5! + ... + n terms
double calculateSeriesS10(int n)
{
    double sum = 0.0;
    double term = 1.0;
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        term /= factorial;
        sum += term;
        factorial += 2;
    }
    return sum;
}

// Function to calculate the sum of the series S = 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+20)
int calculateSeriesS11()
{
    int sum = 0;
    int term = 0;
    for (int i = 1; i <= 20; i++)
    {
        term += i;
        sum += term;
    }
    return sum;
}

// Function to calculate the sum of the series S = x + x^2/2! + x^3/3! + ... + x^10/10!
double calculateSeriesS12(double x)
{
    double sum = 0.0;
    double term = x;
    int factorial = 1;
    for (int i = 1; i <= 10; i++)
    {
        term /= factorial;
        sum += term;
        term *= x;
        factorial *= (i + 1);
    }
    return sum;
}

// Function to calculate the sum of the series P = x/2! + x^2/3! + ... + x^9/10!
double calculateSeriesP13(double x)
{
    double sum = 0.0;
    double term = x;
    int factorial = 2;
    for (int i = 1; i <= 9; i++)
    {
        term /= factorial;
        sum += term;
        term *= x;
        factorial *= (i + 2);
    }
    return sum;
}

// Function to calculate the sum of the series S = 1 - 2 + 3 - 4 + ... + (-1)^n * n
int calculateSeriesS14(int n)
{
    int sum = 0;
    int sign = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += sign * i;
        sign *= -1;
    }
    return sum;
}

// Function to calculate the sum of the series S = 1 - 2^2 + 3 - 4^2 + ... + (-1)^n * n^2
int calculateSeriesS15(int n)
{
    int sum = 0;
    int sign = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += sign * i * i;
        sign *= -1;
    }
    return sum;
}

// Function to calculate the sum of the series S = 1/(1+2) + 3/(3+5) + ... + 15/(15+16)
double calculateSeriesS16()
{
    double sum = 0.0;
    double numerator = 1.0;
    double denominator = 3.0;
    for (int i = 1; i <= 15; i++)
    {
        sum += numerator / (numerator + denominator);
        numerator += 2;
        denominator += 1;
    }
    return sum;
}

// Function to calculate the sum of the series S = 1 + x^2/2! - x^4/4! + ... + (-1)^n * x^(2n)/(2n)!
double calculateSeriesS17(double x, int n)
{
    double sum = 0.0;
    double term = 1.0;
    int factorial = 2;
    int sign = 1;
    for (int i = 1; i <= n; i++)
    {
        term *= x * x;
        term /= factorial;
        sum += sign * term;
        factorial *= (2 * i + 1) * (2 * i + 2);
        sign *= -1;
    }
    return sum;
}

// Function to calculate the sum of the series S = 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+20)
int calculateSeriesS18()
{
    int sum = 0;
    int term = 0;
    for (int i = 1; i <= 20; i++)
    {
        term += i;
        sum += term;
    }
    return sum;
}

// Function to calculate the sum of the series S = 1 + x + x^2/2 + x^3/3 + ... + x^n/n
double calculateSeriesS19(double x, int n)
{
    double sum = 1.0;
    double term = x;
    for (int i = 1; i <= n; i++)
    {
        term *= x;
        term /= i;
        sum += term;
    }
    return sum;
}

// Function to calculate the sum of the series S = 1*3/2*4*5 + 2*4/3*5*6 + 3*5/4*6*7 + ... + n*(n+2)/(n+1)*(n+3)*(n+4)
double calculateSeriesS20(int n)
{
    double sum = 0.0;
    double numerator = 1.0;
    double denominator = 2.0;
    for (int i = 1; i <= n; i++)
    {
        sum += numerator * (numerator + 2) / (denominator * (denominator + 1) * (denominator + 3) * (denominator + 4));
        numerator += 1;
        denominator += 1;
    }
    return sum;
}

int main()
{
    double resultS, resultS12, resultP13, resultS16, resultS17, resultS19, resultS20;
    int resultS11, resultS14, resultS15, n;

    printf("Series Calculations:\n");

    // Series S = 1/1! + 1/2! + 1/3! + ... + 1/n!
    resultS = calculateSeriesS();
    printf("i. S = %.2lf\n", resultS);

    // Series S = 1 + 1/3! + 1/5! + ... + n terms
    printf("x. Enter the number of terms for series S: ");
    scanf("%d", &n);
    resultS = calculateSeriesS10(n);
    printf("x. S = %.2lf\n", resultS);

    // Series S = 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+20)
    resultS11 = calculateSeriesS11();
    printf("xi. S = %d\n", resultS11);

    // Series S = x + x^2/2! + x^3/3! + ... + x^10/10!
    double x;
    printf("xii. Enter the value of x for series S(x): ");
    scanf("%lf", &x);
    resultS12 = calculateSeriesS12(x);
    printf("xii. S = %.2lf\n", resultS12);

    // Series P = x/2! + x^2/3! + ... + x^9/10!
    printf("xiii. Enter the value of x for series P(x): ");
    scanf("%lf", &x);
    resultP13 = calculateSeriesP13(x);
    printf("xiii. P = %.2lf\n", resultP13);

    // Series S = 1 - 2 + 3 - 4 + ... + (-1)^n * n
    printf("xiv. Enter the value of n for series S: ");
    scanf("%d", &n);
    resultS14 = calculateSeriesS14(n);
    printf("xiv. S = %d\n", resultS14);

    // Series S = 1 - 2^2 + 3 - 4^2 + ... + (-1)^n * n^2
    printf("xv. Enter the value of n for series S: ");
    scanf("%d", &n);
    resultS15 = calculateSeriesS15(n);
    printf("xv. S = %d\n", resultS15);

    // Series S = 1/(1+2) + 3/(3+5) + ... + 15/(15+16)
    resultS16 = calculateSeriesS16();
    printf("xvi. S = %.2lf\n", resultS16);

    // Series S = 1 + x^2/2! - x^4/4! + ... + (-1)^n * x^(2n)/(2n)!
    printf("xvii. Enter the value of x for series S(x): ");
    scanf("%lf", &x);
    printf("xvii. Enter the number of terms for series S(x): ");
    scanf("%d", &n);
    resultS17 = calculateSeriesS17(x, n);
    printf("xvii. S = %.2lf\n", resultS17);

    // Series S = 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+20)
    resultS18 = calculateSeriesS18();
    printf("xviii. S = %d\n", resultS18);

    // Series S = 1 + x + x^2/2 + x^3/3 + ... + x^n/n
    printf("xix. Enter the value of x for series S(x): ");
    scanf("%lf", &x);
    printf("xix. Enter the value of n for series S(x): ");
    scanf("%d", &n);
    resultS19 = calculateSeriesS19(x, n);
    printf("xix. S = %.2lf\n", resultS19);

    // Series S = 1 * 3/2 * 4 * 5 + 2 * 4/3 * 5 * 6 + 3 * 5/4 * 6 * 7 + ... + n * (n+2)/(n+1) * (n+3) * (n+4)
    printf("xx. Enter the value of n for series S: ");
    scanf("%d", &n);
    resultS20 = calculateSeriesS20(n);
    printf("xx. S = %.2lf\n", resultS20);

    return 0;
}
