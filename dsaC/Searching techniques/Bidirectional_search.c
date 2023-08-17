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

bool bidirectionalSearch(int graph[MAX_NODES][MAX_NODES], int start, int goal)
{
    Queue *forwardQueue = createQueue();
    Queue *backwardQueue = createQueue();
    bool forwardVisited[MAX_NODES] = {false};
    bool backwardVisited[MAX_NODES] = {false};

    enqueue(forwardQueue, start);
    enqueue(backwardQueue, goal);
    forwardVisited[start] = true;
    backwardVisited[goal] = true;

    while (!isQueueEmpty(forwardQueue) && !isQueueEmpty(backwardQueue))
    {
        int currentForward = dequeue(forwardQueue);
        int currentBackward = dequeue(backwardQueue);

        if (forwardVisited[currentForward] && backwardVisited[currentForward])
        {
            printf("Meeting point found at node %d\n", currentForward);
            return true;
        }
        if (forwardVisited[currentBackward] && backwardVisited[currentBackward])
        {
            printf("Meeting point found at node %d\n", currentBackward);
            return true;
        }

        for (int i = 0; i < MAX_NODES; i++)
        {
            if (graph[currentForward][i] == 1 && !forwardVisited[i])
            {
                enqueue(forwardQueue, i);
                forwardVisited[i] = true;
            }
            if (graph[currentBackward][i] == 1 && !backwardVisited[i])
            {
                enqueue(backwardQueue, i);
                backwardVisited[i] = true;
            }
        }
    }

    return false;
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

    if (bidirectionalSearch(graph, start, goal))
    {
        printf("Path found between nodes %d and %d\n", start, goal);
    }
    else
    {
        printf("No path found between nodes %d and %d\n", start, goal);
    }

    return 0;
}
