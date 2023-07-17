#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for linear queue
struct LinearQueue
{
    int data[MAX_SIZE];
    int front;
    int rear;
};

// Function to create an empty linear queue
struct LinearQueue *createLinearQueue()
{
    struct LinearQueue *queue = (struct LinearQueue *)malloc(sizeof(struct LinearQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the linear queue is empty
int isLinearQueueEmpty(struct LinearQueue *queue)
{
    return (queue->front == -1);
}

// Function to check if the linear queue is full
int isLinearQueueFull(struct LinearQueue *queue)
{
    return (queue->rear == MAX_SIZE - 1);
}

// Function to enqueue an element into the linear queue
void linearEnqueue(struct LinearQueue *queue, int item)
{
    if (isLinearQueueFull(queue))
    {
        printf("Linear Queue Overflow\n");
        return;
    }
    if (isLinearQueueEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = item;
    printf("Enqueued %d into the linear queue\n", item);
}

// Function to dequeue an element from the linear queue
int linearDequeue(struct LinearQueue *queue)
{
    if (isLinearQueueEmpty(queue))
    {
        printf("Linear Queue Underflow\n");
        return -1;
    }
    int item = queue->data[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    return item;
}

// Function to display the elements of the linear queue
void displayLinearQueue(struct LinearQueue *queue)
{
    if (isLinearQueueEmpty(queue))
    {
        printf("Linear Queue is empty\n");
        return;
    }
    printf("Linear Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main()
{
    struct LinearQueue *queue = createLinearQueue();

    linearEnqueue(queue, 10);
    linearEnqueue(queue, 20);
    linearEnqueue(queue, 30);
    displayLinearQueue(queue);

    int dequeued = linearDequeue(queue);
    if (dequeued != -1)
    {
        printf("Dequeued element: %d\n", dequeued);
    }
    displayLinearQueue(queue);

    free(queue);

    return 0;
}
