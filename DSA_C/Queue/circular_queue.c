#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for circular queue
struct CircularQueue
{
    int data[MAX_SIZE];
    int front;
    int rear;
};

// Function to create an empty circular queue
struct CircularQueue *createCircularQueue()
{
    struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the circular queue is empty
int isCircularQueueEmpty(struct CircularQueue *queue)
{
    return (queue->front == -1);
}

// Function to check if the circular queue is full
int isCircularQueueFull(struct CircularQueue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue an element into the circular queue
void circularEnqueue(struct CircularQueue *queue, int item)
{
    if (isCircularQueueFull(queue))
    {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (isCircularQueueEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = item;
    printf("Enqueued %d into the circular queue\n", item);
}

// Function to dequeue an element from the circular queue
int circularDequeue(struct CircularQueue *queue)
{
    if (isCircularQueueEmpty(queue))
    {
        printf("Circular Queue Underflow\n");
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
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

// Function to display the elements of the circular queue
void displayCircularQueue(struct CircularQueue *queue)
{
    if (isCircularQueueEmpty(queue))
    {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = queue->front;
    while (i != queue->rear)
    {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->data[i]);
}

int main()
{
    struct CircularQueue *queue = createCircularQueue();

    circularEnqueue(queue, 10);
    circularEnqueue(queue, 20);
    circularEnqueue(queue, 30);
    displayCircularQueue(queue);

    int dequeued = circularDequeue(queue);
    if (dequeued != -1)
    {
        printf("Dequeued element: %d\n", dequeued);
    }
    displayCircularQueue(queue);

    free(queue);

    return 0;
}
