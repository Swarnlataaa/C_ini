#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void sortWord(char *word)
{
    int length = strlen(word);
    int i, j;

    // Use Bubble Sort algorithm to sort the characters in the word
    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (word[j] > word[j + 1])
            {
                // Swap characters
                char temp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char word[MAX_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    sortWord(word);

    printf("Sorted word: %s\n", word);

    return 0;
}
