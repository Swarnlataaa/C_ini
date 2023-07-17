#include <stdio.h>

void functionA(int n);

void functionB(int n)
{
    if (n > 0)
    {
        printf("Function B: %d\n", n);
        functionA(n - 1); // Call to functionA
    }
}

void functionA(int n)
{
    if (n > 0)
    {
        printf("Function A: %d\n", n);
        functionB(n - 1); // Call to functionB
    }
}

int main()
{
    int number = 5;

    // Call functionA to start the chain of indirect recursion
    functionA(number);

    return 0;
}
