#include <stdio.h>
#include <math.h>

// Function to calculate the volume of a cube
double calculateCubeVolume(double side)
{
    return side * side * side;
}

// Function to calculate the volume of a cuboid
double calculateCuboidVolume(double length, double width, double height)
{
    return length * width * height;
}

// Function to calculate the volume of a cylinder
double calculateCylinderVolume(double radius, double height)
{
    return 3.14159 * radius * radius * height;
}

// Function to calculate the volume of a sphere
double calculateSphereVolume(double radius)
{
    return (4.0 / 3.0) * 3.14159 * pow(radius, 3);
}

int main()
{
    double side, length, width, height, radius;

    printf("Formulas and Calculations:\n");

    // Volume of a cube
    printf("i. Volume of a Cube:\n");
    printf("Formula: V = side * side * side\n");
    printf("Enter the side length of the cube: ");
    scanf("%lf", &side);
    printf("Volume: %.2lf\n\n", calculateCubeVolume(side));

    // Volume of a cuboid
    printf("ii. Volume of a Cuboid:\n");
    printf("Formula: V = length * width * height\n");
    printf("Enter the length, width, and height of the cuboid: ");
    scanf("%lf %lf %lf", &length, &width, &height);
    printf("Volume: %.2lf\n\n", calculateCuboidVolume(length, width, height));

    // Volume of a cylinder
    printf("iii. Volume of a Cylinder:\n");
    printf("Formula: V = π * radius * radius * height\n");
    printf("Enter the radius and height of the cylinder: ");
    scanf("%lf %lf", &radius, &height);
    printf("Volume: %.2lf\n\n", calculateCylinderVolume(radius, height));

    // Volume of a sphere
    printf("iv. Volume of a Sphere:\n");
    printf("Formula: V = (4/3) * π * radius^3\n");
    printf("Enter the radius of the sphere: ");
    scanf("%lf", &radius);
    printf("Volume: %.2lf\n\n", calculateSphereVolume(radius));

    return 0;
}
