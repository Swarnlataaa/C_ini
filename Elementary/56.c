#include <stdio.h>

// Function to calculate the area of a triangle
double calculateTriangleArea(double base, double height)
{
    return 0.5 * base * height;
}

// Function to calculate the area of a circle
double calculateCircleArea(double radius)
{
    return 3.14159 * radius * radius;
}

// Function to calculate the area of a square
double calculateSquareArea(double side)
{
    return side * side;
}

// Function to calculate the area of a rectangle
double calculateRectangleArea(double length, double width)
{
    return length * width;
}

int main()
{
    int choice;
    double area;

    // Display menu and get user's choice
    printf("Select a shape:\n");
    printf("1. Triangle\n");
    printf("2. Circle\n");
    printf("3. Square\n");
    printf("4. Rectangle\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Calculate area based on user's choice
    switch (choice)
    {
    case 1:
    {
        double base, height;
        printf("Enter the base and height of the triangle: ");
        scanf("%lf %lf", &base, &height);
        area = calculateTriangleArea(base, height);
        break;
    }
    case 2:
    {
        double radius;
        printf("Enter the radius of the circle: ");
        scanf("%lf", &radius);
        area = calculateCircleArea(radius);
        break;
    }
    case 3:
    {
        double side;
        printf("Enter the side length of the square: ");
        scanf("%lf", &side);
        area = calculateSquareArea(side);
        break;
    }
    case 4:
    {
        double length, width;
        printf("Enter the length and width of the rectangle: ");
        scanf("%lf %lf", &length, &width);
        area = calculateRectangleArea(length, width);
        break;
    }
    default:
        printf("Invalid choice\n");
        return 0;
    }

    // Print the calculated area
    printf("Area: %.2lf\n", area);

    return 0;
}
