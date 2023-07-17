#include <stdio.h>

#define MAX_LENGTH 1000

void countCharactersWordsLines(const char *text, int *charCount, int *wordCount, int *lineCount)
{
    *charCount = 0;
    *wordCount = 0;
    *lineCount = 0;

    int i = 0;
    int inWord = 0;

    while (text[i] != '\0')
    {
        (*charCount)++;

        if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n')
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            inWord = 1;
            (*wordCount)++;
        }

        if (text[i] == '\n')
        {
            (*lineCount)++;
        }

        i++;
    }
}

int main()
{
    char text[MAX_LENGTH];

    printf("Enter text (press Ctrl+Z followed by Enter to end input):\n");

    int c;
    int i = 0;
    while ((c = getchar()) != EOF && i < MAX_LENGTH - 1)
    {
        text[i++] = c;
    }
    text[i] = '\0';

    int charCount, wordCount, lineCount;

    countCharactersWordsLines(text, &charCount, &wordCount, &lineCount);

    printf("Character count: %d\n", charCount);
    printf("Word count: %d\n", wordCount);
    printf("Line count: %d\n", lineCount);

    return 0;
}
