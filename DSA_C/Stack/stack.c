#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack
{
    int data[MAX_SIZE];
    int top;
};

// Function to create an empty stack
struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
    printf("Pushed %d onto the stack\n", item);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

// Function to count the number of elements in the stack
int count(struct Stack *stack)
{
    return stack->top + 1;
}

// Function to change the value at a specified index in the stack
void change(struct Stack *stack, int index, int newValue)
{
    if (index < 0 || index > stack->top)
    {
        printf("Invalid index\n");
        return;
    }
    stack->data[index] = newValue;
    printf("Value at index %d changed to %d\n", index, newValue);
}

// Function to display the elements in the stack
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack *stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);

    int popped = pop(stack);
    if (popped != -1)
    {
        printf("Popped element: %d\n", popped);
    }
    display(stack);

    int topElement = peek(stack);
    if (topElement != -1)
    {
        printf("Top element: %d\n", topElement);
    }

    int stackCount = count(stack);
    printf("Number of elements in stack: %d\n", stackCount);

    change(stack, 1, 50);
    display(stack);

    free(stack);

    return 0;
}
