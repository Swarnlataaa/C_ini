#include <stdio.h>

int main()
{
    printf("Pythagorean Triplets within 100:\n");

    // Iterate over possible values of 'a'
    for (int a = 1; a <= 100; a++)
    {
        // Iterate over possible values of 'b'
        for (int b = a; b <= 100; b++)
        {
            // Calculate 'c' using the Pythagorean theorem
            int c = a * a + b * b;

            // Check if 'c' is a perfect square and within the range
            int squareRoot = (int)sqrt(c);
            if (squareRoot * squareRoot == c && squareRoot <= 100)
            {
                printf("%d, %d, %d\n", a, b, squareRoot);
            }
        }
    }

    return 0;
}
