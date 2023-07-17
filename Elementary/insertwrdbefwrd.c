#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void insertWordBefore(char *text, const char *givenWord, const char *insertWord)
{
    char *position = strstr(text, givenWord);

    if (position != NULL)
    {
        int givenWordLength = strlen(givenWord);
        int insertWordLength = strlen(insertWord);
        int textLength = strlen(text);
        int shiftLength = insertWordLength - givenWordLength;

        // Shift the text to make room for the insert word
        memmove(position + insertWordLength, position + givenWordLength, textLength - (position - text) - givenWordLength + 1);

        // Copy the insert word to the position
        memcpy(position, insertWord, insertWordLength);
    }
}

int main()
{
    char text[MAX_LENGTH];
    char givenWord[MAX_LENGTH];
    char insertWord[MAX_LENGTH];

    printf("Enter a line of text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the word to insert before: ");
    scanf("%s", givenWord);

    printf("Enter the word to insert: ");
    scanf("%s", insertWord);

    insertWordBefore(text, givenWord, insertWord);

    printf("Modified text: %s\n", text);

    return 0;
}
