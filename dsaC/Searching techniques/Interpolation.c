#include <stdio.h>

double linearInterpolation(double x0, double y0, double x1, double y1, double x)
{
    return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
}

int main()
{
    double x0 = 2.0;
    double y0 = 4.0;
    double x1 = 5.0;
    double y1 = 7.0;
    double x = 3.5;

    double interpolatedValue = linearInterpolation(x0, y0, x1, y1, x);

    printf("Interpolated value at x = %.2lf: %.2lf\n", x, interpolatedValue);

    return 0;
}
