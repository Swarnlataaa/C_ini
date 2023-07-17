#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle
double calculateTriangleArea(double p, double q, double r)
{
    double s = (p + q + r) / 2.0;
    double area = sqrt(s * (s - p) * (s - q) * (s - r));
    return area;
}

int main()
{
    double side1, side2, side3;

    // Input the three sides of the triangle
    printf("Enter the length of side 1: ");
    scanf("%lf", &side1);
    printf("Enter the length of side 2: ");
    scanf("%lf", &side2);
    printf("Enter the length of side 3: ");
    scanf("%lf", &side3);

    // Calculate the area of the triangle using the calculateTriangleArea function
    double area = calculateTriangleArea(side1, side2, side3);

    // Print the area of the triangle
    printf("Area of the triangle: %.2lf\n", area);

    return 0;
}
