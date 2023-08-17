#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

void precomputeBadCharacter(char pattern[], int patternLength, int badCharTable[])
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        badCharTable[i] = -1; // Initialize all characters to -1
    }

    for (int i = 0; i < patternLength; i++)
    {
        badCharTable[(int)pattern[i]] = i;
    }
}

void searchBoyerMoore(char text[], char pattern[])
{
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    int badCharTable[ALPHABET_SIZE];
    precomputeBadCharacter(pattern, patternLength, badCharTable);

    int shift = 0;

    while (shift <= textLength - patternLength)
    {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
        {
            j--;
        }

        if (j < 0)
        {
            printf("Pattern found at index %d\n", shift);
            shift += (shift + patternLength < textLength) ? patternLength - badCharTable[text[shift + patternLength]] : 1;
        }
        else
        {
            int badCharShift = j - badCharTable[text[shift + j]];
            int goodSuffixShift = 1;

            if (j < patternLength - 1)
            {
                int suffixLength = patternLength - 1 - j;
                goodSuffixShift = patternLength - suffixLength;
            }

            shift += (badCharShift > goodSuffixShift) ? badCharShift : goodSuffixShift;
        }
    }
}

int main()
{
    char text[] = "AABAACAADAABAAABAA";
    char pattern[] = "AABA";

    searchBoyerMoore(text, pattern);

    return 0;
}
