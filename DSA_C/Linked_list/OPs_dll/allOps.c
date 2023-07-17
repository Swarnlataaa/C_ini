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

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to delete a node from the list
void deleteNode(struct Node **head, int value)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *current = *head;
    while (current != NULL && current->data != value)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        return;
    }

    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        *head = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    free(current);
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

int main()
{
    struct Node *head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Linked List after inserting at the beginning: ");
    traverseLinkedList(head);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Linked List after inserting at the end: ");
    traverseLinkedList(head);

    // Delete a node from the list
    deleteNode(&head, 3);

    printf("Linked List after deleting a node: ");
    traverseLinkedList(head);

    // Free the memory allocated for the nodes
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
