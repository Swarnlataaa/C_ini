#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int countOccurrences(const char *text, const char *word)
{
    int count = 0;
    int textLength = strlen(text);
    int wordLength = strlen(word);
    int i, j;

    for (i = 0; i <= textLength - wordLength; i++)
    {
        int found = 1;

        for (j = 0; j < wordLength; j++)
        {
            if (text[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }

        if (found)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    char text[MAX_LENGTH];
    char word[MAX_LENGTH];

    printf("Enter a line of text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter a word: ");
    scanf("%s", word);

    int occurrences = countOccurrences(text, word);

    printf("Number of occurrences of '%s' in the text: %d\n", word, occurrences);

    return 0;
}
