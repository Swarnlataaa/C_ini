#include <stdio.h>
int Fibonacci(int);
void main()
{
    int term, i;
    printf("Enter the number of terms of Fibonacci Series which is going to be printed");
    scanf("% d", &term);
    for (i = 0; i < term; i++)
    {
        printf("% d", Fibonacci(i));
    }
}
int Fibonacci(int x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return (Fibonacci(x - 1) + Fibonacci(x - 2));
}