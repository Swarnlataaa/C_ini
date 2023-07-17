#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph using sequential representation (adjacency matrix)
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
void addEdge(struct Graph *graph, int source, int destination)
{
    if (source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices)
    {
        graph->adjacencyMatrix[source][destination] = 1;
        graph->adjacencyMatrix[destination][source] = 1;
    }
}

// Function to print the graph
void printGraph(struct Graph *graph)
{
    printf("Graph (Sequential Representation - Adjacency Matrix):\n");
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
    struct Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
/*adjacency matrix*/
