#include <stdio.h>
#include <math.h>

// Define structure for a point
struct Point
{
    float x;
    float y;
};

// Function to calculate distance between two points
float calculateDistance(const struct Point *p1, const struct Point *p2)
{
    float distance;
    distance = sqrt(pow((p2->x - p1->x), 2) + pow((p2->y - p1->y), 2));
    return distance;
}

int main()
{
    struct Point point1, point2;

    // Read coordinates of first point
    printf("Enter x-coordinate of first point: ");
    scanf("%f", &(point1.x));

    printf("Enter y-coordinate of first point: ");
    scanf("%f", &(point1.y));

    // Read coordinates of second point
    printf("Enter x-coordinate of second point: ");
    scanf("%f", &(point2.x));

    printf("Enter y-coordinate of second point: ");
    scanf("%f", &(point2.y));

    // Calculate and display distance
    float distance = calculateDistance(&point1, &point2);
    printf("Distance between the points: %.2f\n", distance);

    return 0;
}
