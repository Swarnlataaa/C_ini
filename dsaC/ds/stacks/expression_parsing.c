#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
typedef struct
{
    int top;
    char items[MAX_SIZE];
} Stack;

// Initialize stack
void initialize(Stack *s)
{
    s->top = -1;
}

// Push operation
void push(Stack *s, char c)
{
    if (s->top < MAX_SIZE - 1)
    {
        s->items[++(s->top)] = c;
    }
    else
    {
        printf("Stack is full\n");
        exit(1);
    }
}

// Pop operation
char pop(Stack *s)
{
    if (s->top >= 0)
    {
        return s->items[(s->top)--];
    }
    else
    {
        printf("Stack is empty\n");
        exit(1);
    }
}

// Function to check if character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get precedence of an operator
int getPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    initialize(&s);
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(&s, c);
        }
        else if (c == ')')
        {
            while (s.top >= 0 && s.items[s.top] != '(')
            {
                postfix[j++] = pop(&s);
            }
            if (s.top >= 0 && s.items[s.top] == '(')
            {
                pop(&s);
            }
            else
            {
                printf("Invalid expression\n");
                exit(1);
            }
        }
        else if (isOperator(c))
        {
            while (s.top >= 0 && getPrecedence(s.items[s.top]) >= getPrecedence(c))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
        else
        {
            printf("Invalid character in expression\n");
            exit(1);
        }

        i++;
    }

    while (s.top >= 0)
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

// Function to evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    Stack s;
    initialize(&s);
    int i = 0;

    while (postfix[i] != '\0')
    {
        char c = postfix[i];

        if (isdigit(c))
        {
            push(&s, c - '0');
        }
        else if (isOperator(c))
        {
            int operand2 = pop(&s);
            int operand1 = pop(&s);

            switch (c)
            {
            case '+':
                push(&s, operand1 + operand2);
                break;
            case '-':
                push(&s, operand1 - operand2);
                break;
            case '*':
                push(&s, operand1 * operand2);
                break;
            case '/':
                push(&s, operand1 / operand2);
                break;
            }
        }

        i++;
    }

    return pop(&s);
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
