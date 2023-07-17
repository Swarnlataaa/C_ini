#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node **head, int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        // If the list is empty, make the new node the head
        *head = newNode;
    }
    else
    {
        // Find the last node and append the new node
        struct Node *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
    }
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
    struct Node *head = NULL;

    // Insert nodes at the end of the list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    // Print the elements of the linked list
    printf("Linked List: ");
    printLinkedList(head);

    return 0;
}
