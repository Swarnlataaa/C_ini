#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to print the elements of the doubly linked list
void printDoublyLinkedList(struct Node *head)
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
    // Create the nodes for the doubly linked list
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocate memory for the nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Assign data values and link the nodes
    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    // Print the elements of the doubly linked list
    printf("Doubly Linked List: ");
    printDoublyLinkedList(head);

    // Free the memory allocated for the nodes
    free(head);
    free(second);
    free(third);

    return 0;
}
