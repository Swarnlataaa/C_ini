#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct
{
    bool isInVertexCover;
    int degree;
} VertexInfo;

typedef struct
{
    int edges[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

Graph createGraph(int numVertices)
{
    Graph graph;
    graph.numVertices = numVertices;
    graph.numEdges = 0;
    return graph;
}

int maxDegreeVertex(VertexInfo vertexInfo[], int numVertices)
{
    int maxDegree = -1;
    int maxDegreeVertex = -1;

    for (int v = 0; v < numVertices; v++)
    {
        if (!vertexInfo[v].isInVertexCover && vertexInfo[v].degree > maxDegree)
        {
            maxDegree = vertexInfo[v].degree;
            maxDegreeVertex = v;
        }
    }

    return maxDegreeVertex;
}

void vertexCover(Graph graph)
{
    VertexInfo vertexInfo[MAX_VERTICES];

    for (int v = 0; v < graph.numVertices; v++)
    {
        vertexInfo[v].isInVertexCover = false;
        vertexInfo[v].degree = 0;
    }

    for (int v = 0; v < graph.numVertices; v++)
    {
        for (int u = 0; u < graph.numVertices; u++)
        {
            if (graph.edges[v][u])
            {
                vertexInfo[v].degree++;
                vertexInfo[u].degree++;
            }
        }
    }

    while (true)
    {
        int v = maxDegreeVertex(vertexInfo, graph.numVertices);
        if (v == -1)
        {
            break;
        }
        vertexInfo[v].isInVertexCover = true;

        for (int u = 0; u < graph.numVertices; u++)
        {
            if (graph.edges[v][u])
            {
                graph.edges[v][u] = 0;
                graph.edges[u][v] = 0;
                vertexInfo[u].degree--;
            }
        }
    }

    printf("Vertices in Vertex Cover:\n");
    for (int v = 0; v < graph.numVertices; v++)
    {
        if (vertexInfo[v].isInVertexCover)
        {
            printf("%d ", v);
        }
    }
    printf("\n");
}

int main()
{
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    Graph graph = createGraph(numVertices);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < numEdges; i++)
    {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph.edges[vertex1][vertex2] = 1;
        graph.edges[vertex2][vertex1] = 1;
        graph.numEdges++;
    }

    vertexCover(graph);

    return 0;
}
