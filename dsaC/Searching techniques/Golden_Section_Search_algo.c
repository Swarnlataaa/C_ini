#include <stdio.h>
#include <math.h>

#define GOLDEN_RATIO 1.61803398875

double func(double x)
{
    return x * x - 4 * x; // Example function: f(x) = x^2 - 4x
}

double goldenSectionSearch(double a, double b, double epsilon)
{
    double x1 = b - (b - a) / GOLDEN_RATIO;
    double x2 = a + (b - a) / GOLDEN_RATIO;
    double f1 = func(x1);
    double f2 = func(x2);

    while (fabs(b - a) > epsilon)
    {
        if (f1 < f2)
        {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - (b - a) / GOLDEN_RATIO;
            f1 = func(x1);
        }
        else
        {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + (b - a) / GOLDEN_RATIO;
            f2 = func(x2);
        }
    }

    return (a + b) / 2;
}

int main()
{
    double a = 0.0;          // Start of interval
    double b = 5.0;          // End of interval
    double epsilon = 0.0001; // Tolerance

    double min = goldenSectionSearch(a, b, epsilon);

    printf("Minimum value of the function occurs at x = %lf\n", min);
    printf("Minimum function value: %lf\n", func(min));

    return 0;
}
