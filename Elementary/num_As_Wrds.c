#include <stdio.h>

// Recursive function to display a positive integer in words
void displayNumberInWords(int n)
{
    // Base case: When n is 0
    if (n == 0)
    {
        return;
    }

    // Recursive call with the quotient of n divided by 10
    displayNumberInWords(n / 10);

    // Print the word representation of the last digit
    switch (n % 10)
    {
    case 0:
        printf("zero ");
        break;
    case 1:
        printf("one ");
        break;
    case 2:
        printf("two ");
        break;
    case 3:
        printf("three ");
        break;
    case 4:
        printf("four ");
        break;
    case 5:
        printf("five ");
        break;
    case 6:
        printf("six ");
        break;
    case 7:
        printf("seven ");
        break;
    case 8:
        printf("eight ");
        break;
    case 9:
        printf("nine ");
        break;
    }
}

int main()
{
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number >= 0)
    {
        printf("Number in words: ");
        if (number == 0)
        {
            printf("zero");
        }
        else
        {
            displayNumberInWords(number);
        }
        printf("\n");
    }
    else
    {
        printf("Number must be non-negative.\n");
    }

    return 0;
}
