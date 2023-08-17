#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define BEAM_WIDTH 2

typedef struct Node
{
    int id;
    struct Node *next;
} Node;

Node *createNode(int id)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node **queue, int id)
{
    Node *newNode = createNode(id);
    if (*queue == NULL)
    {
        *queue = newNode;
        return;
    }
    Node *temp = *queue;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int dequeue(Node **queue)
{
    if (*queue == NULL)
    {
        return -1;
    }
    int id = (*queue)->id;
    Node *temp = *queue;
    *queue = (*queue)->next;
    free(temp);
    return id;
}

bool isQueueEmpty(Node *queue)
{
    return (queue == NULL);
}

void beamSearch(int graph[MAX_NODES][MAX_NODES], int start, int goal)
{
    Node *queue = NULL;
    enqueue(&queue, start);

    while (!isQueueEmpty(queue))
    {
        int current = dequeue(&queue);
        printf("Expanding node: %d\n", current);

        if (current == goal)
        {
            printf("Goal reached!\n");
            return;
        }

        for (int i = 0; i < MAX_NODES; i++)
        {
            if (graph[current][i] == 1)
            {
                enqueue(&queue, i);
            }
        }
    }

    printf("Goal not reached.\n");
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

    int start = 0;
    int goal = 9;

    beamSearch(graph, start, goal);

    return 0;
}
