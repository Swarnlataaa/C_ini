#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node **head, int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;

    // Update the head pointer to point to the new node
    *head = newNode;
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

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the elements of the linked list
    printf("Linked List: ");
    printLinkedList(head);

    return 0;
}
