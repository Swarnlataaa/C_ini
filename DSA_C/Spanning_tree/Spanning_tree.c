#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

// Function to find the vertex with minimum key value from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int vertices)
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the constructed MST stored in parent array
void printMST(int parent[], struct Graph *graph, int vertices)
{
    printf("Minimum Spanning Tree:\n");
    printf("Edge \t\tWeight\n");
    for (int i = 1; i < vertices; i++)
    {
        printf("%d - %d \t\t%d\n", parent[i], i, graph->adjacencyMatrix[i][parent[i]]);
    }
}

// Function to construct and print the Minimum Spanning Tree using Prim's algorithm
void primMST(struct Graph *graph, int vertices)
{
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST

    // MST will have vertices-1 edges
    for (int count = 0; count < vertices - 1; count++)
    {
        int u = minKey(key, mstSet, vertices); // Pick the minimum key vertex from the set of vertices not yet included in MST
        mstSet[u] = true;                      // Add the picked vertex to the MST set

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++)
        {
            if (graph->adjacencyMatrix[u][v] && mstSet[v] == false && graph->adjacencyMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    printMST(parent, graph, vertices);
}

int main()
{
    int vertices = 6;
    struct Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 6);

    primMST(graph, vertices);

    return 0;
}
