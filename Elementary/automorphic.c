#include <stdio.h>

// Function to check if a number is automorphic
int isAutomorphic(int number)
{
    int square = number * number;
    while (number > 0)
    {
        if (number % 10 != square % 10)
        {
            return 0;
        }
        number /= 10;
        square /= 10;
    }
    return 1;
}

int main()
{
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is automorphic
    if (isAutomorphic(number))
    {
        printf("%d is an automorphic number.\n", number);
    }
    else
    {
        printf("%d is not an automorphic number.\n", number);
    }

    return 0;
}
