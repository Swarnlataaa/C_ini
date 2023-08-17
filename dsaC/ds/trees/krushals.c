#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct
{
    int source;
    int destination;
    int weight;
} Edge;

typedef struct
{
    int parent;
    int rank;
} Subset;

typedef struct
{
    Edge edges[MAX_EDGES];
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

int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskalMST(Graph graph)
{
    Edge result[MAX_VERTICES]; // To store the MST edges
    Subset subsets[MAX_VERTICES];

    for (int v = 0; v < graph.numVertices; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    qsort(graph.edges, graph.numEdges, sizeof(graph.edges[0]), compareEdges);

    int e = 0; // Index for result array
    int i = 0; // Index for sorted edges

    while (e < graph.numVertices - 1 && i < graph.numEdges)
    {
        Edge nextEdge = graph.edges[i++];

        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);

        if (x != y)
        {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in MST:\n");
    for (int j = 0; j < e; j++)
    {
        printf("(%d, %d) Weight: %d\n", result[j].source, result[j].destination, result[j].weight);
    }
}

int main()
{
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    Graph graph = createGraph(numVertices);

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < numEdges; i++)
    {
        scanf("%d %d %d", &graph.edges[i].source, &graph.edges[i].destination, &graph.edges[i].weight);
    }

    kruskalMST(graph);

    return 0;
}
