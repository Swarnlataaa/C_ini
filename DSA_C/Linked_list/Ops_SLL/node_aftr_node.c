#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node after a specified node
void insertAfter(struct Node *prevNode, int value)
{
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node *newNode = createNode(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to print the elements of the linked list
void printLinkedList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = createNode(1);
    struct Node *second = createNode(2);
    struct Node *third = createNode(3);

    head->next = second;
    second->next = third;

    printf("Linked List before insertion: ");
    printLinkedList(head);

    insertAfter(second, 4);

    printf("Linked List after insertion: ");
    printLinkedList(head);

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
