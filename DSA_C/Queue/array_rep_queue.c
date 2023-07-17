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
    return (queue->rear == MAX_SIZE - 1);
}

// Function to enqueue an element into the queue
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
    }
    queue->rear++;
    queue->data[queue->rear] = item;
    printf("Enqueued %d into the queue\n", item);
}

// Function to dequeue an element from the queue
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
        queue->front++;
    }
    return item;
}

// Function to display the elements of the queue
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);

    int dequeued = dequeue(queue);
    if (dequeued != -1)
    {
        printf("Dequeued element: %d\n", dequeued);
    }
    display(queue);

    free(queue);

    return 0;
}
