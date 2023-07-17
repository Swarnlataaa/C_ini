#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

// Structure to represent a graph using linked representation (adjacency list)
struct Graph
{
    int vertices;
    struct Node **adjacencyList;
};

// Function to create a node
struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjacencyList = (struct Node **)malloc(vertices * sizeof(struct Node *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int source, int destination)
{
    if (source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices)
    {
        // Add edge from source to destination
        struct Node *newNode = createNode(destination);
        newNode->next = graph->adjacencyList[source];
        graph->adjacencyList[source] = newNode;

        // Add edge from destination to source (for undirected graph)
        newNode = createNode(source);
        newNode->next = graph->adjacencyList[destination];
        graph->adjacencyList[destination] = newNode;
    }
}

// Recursive function for Depth-First Search (DFS)
void DFSRecursive(struct Graph *graph, int vertex, int *visited)
{
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex);

    struct Node *currentNode = graph->adjacencyList[vertex];
    while (currentNode != NULL)
    {
        int adjacentVertex = currentNode->vertex;
        if (!visited[adjacentVertex])
        {
            DFSRecursive(graph, adjacentVertex, visited); // Recursive call for adjacent vertices
        }
        currentNode = currentNode->next;
    }
}

// Function to perform Depth-First Search (DFS) on the graph
void DFS(struct Graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0}; // Array to track visited vertices

    printf("DFS Traversal: ");
    DFSRecursive(graph, startVertex, visited);
}

int main()
{
    int vertices = 7;
    struct Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);

    int startVertex = 0;
    DFS(graph, startVertex);

    return 0;
}
