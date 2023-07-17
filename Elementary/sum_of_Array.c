#include <stdio.h>

int main()
{
    int array[5] = {2, 4, 6, 8, 10};             // Example array
    int size = sizeof(array) / sizeof(array[0]); // Calculate the size of the array
    int sum = 0;
    int i;

    // Compute the sum of array elements
    for (i = 0; i < size; i++)
    {
        sum += array[i];
    }

    // Print the sum
    printf("Sum of array elements: %d\n", sum);

    return 0;
}
