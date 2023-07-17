#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph
{
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a graph
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int source, int destination, int weight)
{
    if (source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices)
    {
        graph->adjacencyMatrix[source][destination] = weight;
        graph->adjacencyMatrix[destination][source] = weight;
    }
}

// Function to find the minimum edge in the graph
void findMinimumEdge(struct Graph *graph, int *minWeight, int *minSrc, int *minDest)
{
    *minWeight = INT_MAX;
    *minSrc = -1;
    *minDest = -1;

    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            if (graph->adjacencyMatrix[i][j] > 0 && graph->adjacencyMatrix[i][j] < *minWeight)
            {
                *minWeight = graph->adjacencyMatrix[i][j];
                *minSrc = i;
                *minDest = j;
            }
        }
    }
}

// Function to perform clustering using spanning tree
void performClustering(struct Graph *graph, int vertices, int clusters)
{
    int minWeight, minSrc, minDest;

    while (clusters > 1)
    {
        findMinimumEdge(graph, &minWeight, &minSrc, &minDest);
        printf("Cluster %d: %d - %d\n", clusters, minSrc, minDest);

        // Merge the clusters by updating the adjacency matrix
        for (int i = 0; i < vertices; i++)
        {
            if (graph->adjacencyMatrix[i][minDest] > 0)
            {
                graph->adjacencyMatrix[i][minDest] = 0;
                graph->adjacencyMatrix[minDest][i] = 0;
                graph->adjacencyMatrix[i][minSrc] = graph->adjacencyMatrix[i][minSrc] + graph->adjacencyMatrix[i][minDest];
                graph->adjacencyMatrix[minSrc][i] = graph->adjacencyMatrix[i][minSrc];
            }
        }

        // Remove the merged vertex
        for (int i = 0; i < vertices; i++)
        {
            graph->adjacencyMatrix[minDest][i] = 0;
            graph->adjacencyMatrix[i][minDest] = 0;
        }

        clusters--;
    }
}

int main()
{
    int vertices = 6;
    int clusters = 3;
    struct Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 6);

    performClustering(graph, vertices, clusters);

    return 0;
}
