#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a directed graph
struct DirectedGraph
{
    int vertices;
    int **adjacencyMatrix;
};

// Function to create a directed graph
struct DirectedGraph *createDirectedGraph(int vertices)
{
    struct DirectedGraph *graph = (struct DirectedGraph *)malloc(sizeof(struct DirectedGraph));
    graph->vertices = vertices;

    graph->adjacencyMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjacencyMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the directed graph
void addDirectedEdge(struct DirectedGraph *graph, int source, int destination)
{
    if (source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices)
    {
        graph->adjacencyMatrix[source][destination] = 1;
    }
}

// Function to print the adjacency matrix of the directed graph
void printDirectedGraph(struct DirectedGraph *graph)
{
    printf("Directed Graph Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int vertices = 5;
    struct DirectedGraph *graph = createDirectedGraph(vertices);

    addDirectedEdge(graph, 0, 1);
    addDirectedEdge(graph, 0, 3);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 2, 4);
    addDirectedEdge(graph, 3, 4);

    printDirectedGraph(graph);

    return 0;
}
