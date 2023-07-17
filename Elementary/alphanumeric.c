#include <stdio.h>
#include <ctype.h>

// Function to check if a character is alphanumeric
int isAlphanumeric(char c)
{
    if (isalnum(c))
    {
        return 1; // Alphanumeric character
    }
    else
    {
        return 0; // Non-alphanumeric character
    }
}

int main()
{
    char character;

    // Input the character
    printf("Enter a character: ");
    scanf(" %c", &character);

    // Check if the character is alphanumeric using the isAlphanumeric function
    if (isAlphanumeric(character))
    {
        printf("The character '%c' is alphanumeric.\n", character);
    }
    else
    {
        printf("The character '%c' is not alphanumeric.\n", character);
    }

    return 0;
}
