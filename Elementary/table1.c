#include <stdio.h>

int main()
{
    // Iterate for each number from 1 to 10
    for (int number = 1; number <= 10; number++)
    {
        printf("Table of %d:\n", number);

        // Print the table for the current number
        for (int i = 1; i <= 10; i++)
        {
            printf("%d x %d = %d\n", number, i, number * i);
        }

        printf("\n"); // Add a line break between tables
    }

    return 0;
}
