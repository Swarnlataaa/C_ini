#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for priority queue
struct PriorityQueue
{
    int data[MAX_SIZE];
    int rear;
};

// Function to create an empty priority queue
struct PriorityQueue *createPriorityQueue()
{
    struct PriorityQueue *queue = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    queue->rear = -1;
    return queue;
}

// Function to check if the priority queue is empty
int isPriorityQueueEmpty(struct PriorityQueue *queue)
{
    return (queue->rear == -1);
}

// Function to check if the priority queue is full
int isPriorityQueueFull(struct PriorityQueue *queue)
{
    return (queue->rear == MAX_SIZE - 1);
}

// Function to enqueue an element into the priority queue
void priorityEnqueue(struct PriorityQueue *queue, int item)
{
    if (isPriorityQueueFull(queue))
    {
        printf("Priority Queue Overflow\n");
        return;
    }
    int i;
    for (i = queue->rear; i >= 0 && queue->data[i] > item; i--)
    {
        queue->data[i + 1] = queue->data[i];
    }
    queue->data[i + 1] = item;
    queue->rear++;
    printf("Enqueued %d into the priority queue\n", item);
}

// Function to dequeue an element from the priority queue
int priorityDequeue(struct PriorityQueue *queue)
{
    if (isPriorityQueueEmpty(queue))
    {
        printf("Priority Queue Underflow\n");
        return -1;
    }
    int item = queue->data[queue->rear];
    queue->rear--;
    return item;
}

// Function to display the elements of the priority queue
void displayPriorityQueue(struct PriorityQueue *queue)
{
    if (isPriorityQueueEmpty(queue))
    {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue elements: ");
    for (int i = 0; i <= queue->rear; i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main()
{
    struct PriorityQueue *queue = createPriorityQueue();

    priorityEnqueue(queue, 30);
    priorityEnqueue(queue, 10);
    priorityEnqueue(queue, 20);
    displayPriorityQueue(queue);

    int dequeued = priorityDequeue(queue);
    if (dequeued != -1)
    {
        printf("Dequeued element: %d\n", dequeued);
    }
    displayPriorityQueue(queue);

    free(queue);

    return 0;
}
