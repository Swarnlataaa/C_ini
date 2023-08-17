#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct
{
    int colors;
    int neighbors[MAX_VERTICES];
} Vertex;

int graph[MAX_VERTICES][MAX_VERTICES];
Vertex vertices[MAX_VERTICES];
int numVertices;

bool isSafe(int v, int c, int color[])
{
    for (int i = 0; i < vertices[v].colors; i++)
    {
        if (graph[v][vertices[v].neighbors[i]] && color[vertices[v].neighbors[i]] == c)
        {
            return false;
        }
    }
    return true;
}

void greedyColoring()
{
    int color[numVertices];

    for (int v = 0; v < numVertices; v++)
    {
        color[v] = -1;
    }

    color[0] = 0;

    for (int v = 1; v < numVertices; v++)
    {
        for (int c = 0; c < numVertices; c++)
        {
            if (isSafe(v, c, color))
            {
                color[v] = c;
                break;
            }
        }
    }

    printf("Vertex \t Color\n");
    for (int v = 0; v < numVertices; v++)
    {
        printf("%d \t %d\n", v, color[v]);
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j])
            {
                vertices[i].neighbors[vertices[i].colors++] = j;
            }
        }
    }

    greedyColoring();

    return 0;
}
