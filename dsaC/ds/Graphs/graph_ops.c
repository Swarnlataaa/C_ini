#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct
{
    int vertex;
    int weight; // You can modify this for weighted graphs
} Edge;

typedef struct
{
    int value;
    // You can add more attributes to your vertex struct
} Vertex;

typedef struct
{
    Vertex vertices[MAX_VERTICES];
    Edge edges[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

Graph createGraph()
{
    Graph graph;
    graph.numVertices = 0;
    graph.numEdges = 0;
    return graph;
}

int addVertex(Graph *graph, int value)
{
    if (graph->numVertices < MAX_VERTICES)
    {
        Vertex newVertex;
        newVertex.value = value;
        graph->vertices[graph->numVertices++] = newVertex;
        return 1; // Successful addition
    }
    return 0; // Max vertices reached
}

int addEdge(Graph *graph, int source, int destination, int weight)
{
    if (source >= 0 && source < graph->numVertices &&
        destination >= 0 && destination < graph->numVertices)
    {

        Edge newEdge;
        newEdge.vertex = destination;
        newEdge.weight = weight; // Modify as needed

        graph->edges[source][graph->numEdges++] = newEdge;
        return 1; // Successful addition
    }
    return 0; // Invalid vertices
}

void displayVertices(Graph *graph)
{
    printf("Vertices:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("%d ", graph->vertices[i].value);
    }
    printf("\n");
}

int main()
{
    Graph graph = createGraph();

    addVertex(&graph, 1);
    addVertex(&graph, 2);
    addVertex(&graph, 3);
    addVertex(&graph, 4);

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 2, 5);
    addEdge(&graph, 1, 3, 8);
    addEdge(&graph, 2, 3, 2);

    displayVertices(&graph);

    return 0;
}
