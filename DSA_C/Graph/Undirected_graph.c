#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent an undirected graph
struct UndirectedGraph
{
    int vertices;
    int **adjacencyMatrix;
};

// Function to create an undirected graph
struct UndirectedGraph *createUndirectedGraph(int vertices)
{
    struct UndirectedGraph *graph = (struct UndirectedGraph *)malloc(sizeof(struct UndirectedGraph));
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

// Function to add an edge to the undirected graph
void addUndirectedEdge(struct UndirectedGraph *graph, int source, int destination)
{
    if (source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices)
    {
        graph->adjacencyMatrix[source][destination] = 1;
        graph->adjacencyMatrix[destination][source] = 1;
    }
}

// Function to print the adjacency matrix of the undirected graph
void printUndirectedGraph(struct UndirectedGraph *graph)
{
    printf("Undirected Graph Adjacency Matrix:\n");
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
    struct UndirectedGraph *graph = createUndirectedGraph(vertices);

    addUndirectedEdge(graph, 0, 1);
    addUndirectedEdge(graph, 0, 3);
    addUndirectedEdge(graph, 1, 2);
    addUndirectedEdge(graph, 2, 4);
    addUndirectedEdge(graph, 3, 4);

    printUndirectedGraph(graph);

    return 0;
}
