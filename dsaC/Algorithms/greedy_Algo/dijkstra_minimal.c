#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct
{
    int distance;
    int visited;
} VertexInfo;

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

int minDistance(VertexInfo distances[])
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numVertices; v++)
    {
        if (!distances[v].visited && distances[v].distance <= min)
        {
            min = distances[v].distance;
            minIndex = v;
        }
    }

    return minIndex;
}

void dijkstra(int startVertex)
{
    VertexInfo distances[MAX_VERTICES];

    for (int v = 0; v < numVertices; v++)
    {
        distances[v].distance = INT_MAX;
        distances[v].visited = 0;
    }

    distances[startVertex].distance = 0;

    for (int count = 0; count < numVertices - 1; count++)
    {
        int u = minDistance(distances);
        distances[u].visited = 1;

        for (int v = 0; v < numVertices; v++)
        {
            if (!distances[v].visited && graph[u][v] && distances[u].distance != INT_MAX && distances[u].distance + graph[u][v] < distances[v].distance)
            {
                distances[v].distance = distances[u].distance + graph[u][v];
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < numVertices; i++)
    {
        printf("%d \t\t %d\n", i, distances[i].distance);
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the weighted adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dijkstra(startVertex);

    return 0;
}
