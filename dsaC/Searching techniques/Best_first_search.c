#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10

typedef struct Node
{
    int id;
    int heuristic; // Heuristic value
    struct Node *next;
} Node;

typedef struct PriorityQueue
{
    Node *front;
} PriorityQueue;

Node *createNode(int id, int heuristic)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = id;
    newNode->heuristic = heuristic;
    newNode->next = NULL;
    return newNode;
}

PriorityQueue *createPriorityQueue()
{
    PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    queue->front = NULL;
    return queue;
}

void enqueue(PriorityQueue *queue, int id, int heuristic)
{
    Node *newNode = createNode(id, heuristic);
    if (queue->front == NULL || heuristic <= queue->front->heuristic)
    {
        newNode->next = queue->front;
        queue->front = newNode;
        return;
    }
    Node *temp = queue->front;
    while (temp->next != NULL && heuristic > temp->next->heuristic)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int dequeue(PriorityQueue *queue)
{
    if (queue->front == NULL)
    {
        return -1;
    }
    int id = queue->front->id;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return id;
}

bool isQueueEmpty(PriorityQueue *queue)
{
    return (queue->front == NULL);
}

void bestFirstSearch(int graph[MAX_NODES][MAX_NODES], int start, int goal)
{
    PriorityQueue *queue = createPriorityQueue();
    enqueue(queue, start, 0);

    while (!isQueueEmpty(queue))
    {
        int current = dequeue(queue);
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
                enqueue(queue, i, /* Calculate heuristic value for node i */);
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

    bestFirstSearch(graph, start, goal);

    return 0;
}
