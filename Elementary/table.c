#include <stdio.h>

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Print the table
    printf("Table of %d:\n", number);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", number, i, number * i);
    }

    return 0;
}
