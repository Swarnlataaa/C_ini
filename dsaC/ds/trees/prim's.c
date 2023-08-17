#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct
{
    int key;
    int parent;
    bool inMST;
} VertexInfo;

typedef struct
{
    int vertices[MAX_VERTICES];
    int weights[MAX_VERTICES];
    int numVertices;
} Graph;

Graph createGraph(int numVertices)
{
    Graph graph;
    graph.numVertices = numVertices;
    return graph;
}

int extractMin(VertexInfo vertexInfo[], int numVertices)
{
    int minIndex = -1;
    int minValue = INT_MAX;

    for (int v = 0; v < numVertices; v++)
    {
        if (!vertexInfo[v].inMST && vertexInfo[v].key < minValue)
        {
            minIndex = v;
            minValue = vertexInfo[v].key;
        }
    }

    return minIndex;
}

void primMST(Graph graph)
{
    VertexInfo vertexInfo[MAX_VERTICES];

    for (int v = 0; v < graph.numVertices; v++)
    {
        vertexInfo[v].key = INT_MAX;
        vertexInfo[v].parent = -1;
        vertexInfo[v].inMST = false;
    }

    vertexInfo[0].key = 0;

    for (int count = 0; count < graph.numVertices - 1; count++)
    {
        int u = extractMin(vertexInfo, graph.numVertices);
        vertexInfo[u].inMST = true;

        for (int v = 0; v < graph.numVertices; v++)
        {
            if (!vertexInfo[v].inMST && graph.weights[u][v] && graph.weights[u][v] < vertexInfo[v].key)
            {
                vertexInfo[v].key = graph.weights[u][v];
                vertexInfo[v].parent = u;
            }
        }
    }

    printf("Edges in MST:\n");
    for (int v = 1; v < graph.numVertices; v++)
    {
        printf("(%d, %d) Weight: %d\n", vertexInfo[v].parent, v, graph.weights[v][vertexInfo[v].parent]);
    }
}

int main()
{
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph graph = createGraph(numVertices);

    printf("Enter the adjacency matrix (weights, 0 for no edge):\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph.weights[i][j]);
        }
    }

    primMST(graph);

    return 0;
}
