#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for queue
struct Queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
};

// Function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue an element
void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->data[queue->rear] = item;
    printf("Enqueued %d\n", item);
}

// Function to dequeue an element
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
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

// Function to peek at the front element of the queue
int peek(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->front];
}

int main()
{
    struct Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    int dequeued = dequeue(queue);
    if (dequeued != -1)
    {
        printf("Dequeued element: %d\n", dequeued);
    }

    int frontElement = peek(queue);
    if (frontElement != -1)
    {
        printf("Front element: %d\n", frontElement);
    }

    free(queue);

    return 0;
}
