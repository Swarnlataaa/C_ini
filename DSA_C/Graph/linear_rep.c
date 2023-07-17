#include <stdio.h>
#include <stdlib.h>

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

// Function to print the graph
void printGraph(struct Graph *graph)
{
    printf("Graph (Linked Representation - Adjacency List):\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *currentNode = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        while (currentNode != NULL)
        {
            printf("%d ", currentNode->vertex);
            currentNode = currentNode->next;
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
/*Adjacency list*/