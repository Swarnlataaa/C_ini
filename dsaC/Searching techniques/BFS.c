#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10

typedef struct Node
{
    int id;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Node *createNode(int id)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, int id)
{
    Node *newNode = createNode(id);
    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        return -1;
    }
    int id = queue->front->id;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return id;
}

bool isQueueEmpty(Queue *queue)
{
    return (queue->front == NULL);
}

void breadthFirstSearch(int graph[MAX_NODES][MAX_NODES], int start, int goal)
{
    Queue *queue = createQueue();
    bool visited[MAX_NODES] = {false};

    enqueue(queue, start);
    visited[start] = true;

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
            if (graph[current][i] == 1 && !visited[i])
            {
                enqueue(queue, i);
                visited[i] = true;
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

    breadthFirstSearch(graph, start, goal);

    return 0;
}
