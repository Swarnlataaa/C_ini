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

// Function to delete an element from the queue
int delete(struct Queue *queue)
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
    printf("Element %d deleted from the queue\n", item);
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

    queue->data[0] = 10;
    queue->data[1] = 20;
    queue->data[2] = 30;
    queue->front = 0;
    queue->rear = 2;
    display(queue);

    int deleted = delete (queue);
    if (deleted != -1)
    {
        printf("Deleted element: %d\n", deleted);
    }
    display(queue);

    free(queue);

    return 0;
}
