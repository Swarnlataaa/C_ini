#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10

typedef struct Node
{
    int id;
    struct Node *next;
} Node;

void dfs(int graph[MAX_NODES][MAX_NODES], bool visited[MAX_NODES], int current)
{
    printf("Visiting node: %d\n", current);
    visited[current] = true;

    for (int i = 0; i < MAX_NODES; i++)
    {
        if (graph[current][i] == 1 && !visited[i])
        {
            dfs(graph, visited, i);
        }
    }
}

int main()
{
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    bool visited[MAX_NODES] = {false};

    for (int i = 0; i < MAX_NODES; i++)
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
        }
    }

    return 0;
}
