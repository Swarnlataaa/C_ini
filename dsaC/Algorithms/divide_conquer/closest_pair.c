#include <stdio.h>
#include <float.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Point;

double distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int compareX(const void *a, const void *b)
{
    return ((Point *)a)->x - ((Point *)b)->x;
}

int compareY(const void *a, const void *b)
{
    return ((Point *)a)->y - ((Point *)b)->y;
}

double bruteForce(Point points[], int n)
{
    double minDist = DBL_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dist = distance(points[i], points[j]);
            if (dist < minDist)
            {
                minDist = dist;
            }
        }
    }

    return minDist;
}

double closestPair(Point points[], int left, int right)
{
    if (right - left <= 3)
    {
        return bruteForce(points + left, right - left);
    }

    int mid = (left + right) / 2;
    double leftMin = closestPair(points, left, mid);
    double rightMin = closestPair(points, mid, right);
    double minDist = fmin(leftMin, rightMin);

    Point strip[right - left];
    int j = 0;

    for (int i = left; i < right; i++)
    {
        if (fabs(points[i].x - points[mid].x) < minDist)
        {
            strip[j] = points[i];
            j++;
        }
    }

    qsort(strip, j, sizeof(Point), compareY);

    for (int i = 0; i < j; i++)
    {
        for (int k = i + 1; k < j && strip[k].y - strip[i].y < minDist; k++)
        {
            double dist = distance(strip[i], strip[k]);
            if (dist < minDist)
            {
                minDist = dist;
            }
        }
    }

    return minDist;
}

double closestPairWrapper(Point points[], int n)
{
    qsort(points, n, sizeof(Point), compareX);
    return closestPair(points, 0, n);
}

int main()
{
    Point points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(points) / sizeof(points[0]);

    double minDist = closestPairWrapper(points, n);

    printf("The closest pair distance is %.6lf\n", minDist);

    return 0;
}
