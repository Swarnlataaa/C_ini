#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print the elements of the linked list
void traverseLinkedList(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to insert a new node after a specified node
void insertAfter(struct Node *prevNode, int value)
{
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node *newNode = createNode(value);

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
    {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
}

int main()
{
    struct Node *head = createNode(1);
    struct Node *second = createNode(2);
    struct Node *third = createNode(4);
    struct Node *fourth = createNode(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    printf("Linked List before insertion: ");
    traverseLinkedList(head);

    // Insert a node after the second node
    insertAfter(second, 3);

    printf("Linked List after insertion: ");
    traverseLinkedList(head);

    // Free memory
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
