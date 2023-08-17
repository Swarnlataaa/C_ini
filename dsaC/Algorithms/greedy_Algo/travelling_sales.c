#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

typedef struct
{
    int x;
    int y;
} Point;

double distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int nearestNeighbor(int numCities, Point cities[], int route[])
{
    int visited[MAX_CITIES] = {0};
    route[0] = 0; // Start from city 0
    visited[0] = 1;
    int totalDistance = 0;

    for (int i = 1; i < numCities; i++)
    {
        int currentCity = route[i - 1];
        int nearestCity = -1;
        double minDist = INT_MAX;

        for (int j = 0; j < numCities; j++)
        {
            if (!visited[j])
            {
                double dist = distance(cities[currentCity], cities[j]);
                if (dist < minDist)
                {
                    minDist = dist;
                    nearestCity = j;
                }
            }
        }

        route[i] = nearestCity;
        visited[nearestCity] = 1;
        totalDistance += minDist;
    }

    // Return to the starting city
    totalDistance += distance(cities[route[numCities - 1]], cities[0]);
    return totalDistance;
}

int main()
{
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    Point cities[MAX_CITIES];

    printf("Enter the coordinates of each city (x y):\n");
    for (int i = 0; i < numCities; i++)
    {
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }

    int route[MAX_CITIES];
    int totalDistance = nearestNeighbor(numCities, cities, route);

    printf("Optimal TSP route: ");
    for (int i = 0; i < numCities; i++)
    {
        printf("%d ", route[i]);
    }
    printf("0\n"); // Return to the starting city

    printf("Total distance traveled: %d\n", totalDistance);

    return 0;
}
