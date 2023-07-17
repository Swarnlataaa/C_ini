#include <stdio.h>

// Function to calculate the sum of the series S = 1 + 1/2 + 1/3 + ... + 1/n
double calculateSeriesS()
{
    double sum = 0.0;
    for (int i = 1; i <= 10; i++)
    {
        sum += 1.0 / i;
    }
    return sum;
}

// Function to calculate the sum of the series P = (1*2) + (2*3) + (3*4) + ... + (n-1)*n
int calculateSeriesP()
{
    int sum = 0;
    for (int i = 1; i <= 9; i++)
    {
        sum += i * (i + 1);
    }
    return sum;
}

// Function to calculate the sum of the series Q = 1/2 + 3/4 + 5/6 + ... + 13/14
double calculateSeriesQ()
{
    double sum = 0.0;
    for (int i = 2; i <= 14; i += 2)
    {
        sum += (i - 1.0) / i;
    }
    return sum;
}

// Function to calculate the sum of the series S = 2/5 + 5/9 + 8/13 + ... + n/d
double calculateSeriesS2(int n, int d)
{
    double sum = 0.0;
    for (int i = 2; i <= n; i += 3)
    {
        sum += (double)i / d;
        d += 4;
    }
    return sum;
}

// Function to calculate the sum of the series S = x + x^2 + x^3 + ... + x^10
double calculateSeriesS3(double x)
{
    double sum = 0.0;
    double term = 1.0;
    for (int i = 1; i <= 10; i++)
    {
        term *= x;
        sum += term;
    }
    return sum;
}

// Function to calculate the sum of the series P = x + x^3/3 + x^5/5 + ... + n terms
double calculateSeriesP2(double x, int n)
{
    double sum = 0.0;
    double term = x;
    for (int i = 1; i <= n; i++)
    {
        sum += term / (2 * i - 1);
        term *= x * x;
    }
    return sum;
}

// Function to calculate the sum of the series S = (13*1) + (12*2) + ... + (1*13)
int calculateSeriesS4()
{
    int sum = 0;
    int n = 13;
    for (int i = 1; i <= 13; i++)
    {
        sum += n * i;
        n--;
    }
    return sum;
}

// Function to calculate the sum of the series S = 1 + 1/(2^2) + 1/(3^3) + ... + 1/(n^n)
double calculateSeriesS5(int n)
{
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
    {
        double term = 1.0;
        for (int j = 1; j <= i; j++)
        {
            term /= i;
        }
        sum += term;
    }
    return sum;
}

int main()
{
    double resultS, resultQ, resultS3, resultP2, resultS5;
    int resultP, resultS4;

    printf("Series Calculations:\n");

    // Series S = 1 + 1/2 + 1/3 + ... + 1/10
    resultS = calculateSeriesS();
    printf("i. S = %.2lf\n", resultS);

    // Series P = (1*2) + (2*3) + (3*4) + ... + (8*9) + (9*10)
    resultP = calculateSeriesP();
    printf("ii. P = %d\n", resultP);

    // Series Q = 1/2 + 3/4 + 5/6 + ... + 13/14
    resultQ = calculateSeriesQ();
    printf("iii. Q = %.2lf\n", resultQ);

    // Series S = 2/5 + 5/9 + 8/13 + ... + n/d
    resultS3 = calculateSeriesS2(10, 5);
    printf("iv. S = %.2lf\n", resultS3);

    // Series S = x + x^2 + x^3 + ... + x^10
    double x;
    printf("Enter the value of x for series S(x): ");
    scanf("%lf", &x);
    resultS3 = calculateSeriesS3(x);
    printf("v. S = %.2lf\n", resultS3);

    // Series P = x + x^3/3 + x^5/5 + ... + n terms
    int n;
    printf("Enter the value of x for series P(x): ");
    scanf("%lf", &x);
    printf("Enter the number of terms for series P(x): ");
    scanf("%d", &n);
    resultP2 = calculateSeriesP2(x, n);
    printf("vi. P = %.2lf\n", resultP2);

    // Series S = (13*1) + (12*2) + ... + (1*13)
    resultS4 = calculateSeriesS4();
    printf("vii. S = %d\n", resultS4);

    // Series S = 1 + 1/(2^2) + 1/(3^3) + ... + 1/(n^n)
    printf("Enter the value of n for series S: ");
    scanf("%d", &n);
    resultS5 = calculateSeriesS5(n);
    printf("viii. S = %.2lf\n", resultS5);

    return 0;
}
