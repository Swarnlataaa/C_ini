#include <stdio.h>

// Recursive function to display a line of text in reverse order
void displayReverseLine()
{
    char c;
    scanf("%c", &c);

    if (c != '\n')
    {
        displayReverseLine(); // Recursive call to read the next character
        printf("%c", c);      // Print the character after the recursive call
    }
}

int main()
{
    printf("Enter a line of text: ");
    displayReverseLine();

    return 0;
}
