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

// Function to delete a node from the list
void deleteNode(struct Node **head, int key)
{
    // If the list is empty, return
    if (*head == NULL)
        return;

    // If the key to be deleted is in the head node
    if ((*head)->data == key)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Find the node to be deleted
    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    // If the key is not found
    if (current == NULL)
        return;

    // Unlink the node from the linked list
    prev->next = current->next;
    free(current);
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
    printf("Linked List before deletion: ");
    printLinkedList(head);

    // Delete a node from the list
    deleteNode(&head, 2);

    // Print the elements of the linked list after deletion
    printf("Linked List after deletion: ");
    printLinkedList(head);

    return 0;
}
