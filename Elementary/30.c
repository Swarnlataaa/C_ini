#include <stdio.h>
int GCD(int, int);
void main()
{
    int a, b, gcd;
    printf("Enter two numbers");
    scanf("% d % d", &a, &b);
    gcd = GCD(a, b);
    printf("GCD of % d and % d is % d", a, b, gcd);
}
int GCD(int x, int y)
{
    if (y == 0)
        return x;
    else
        return GCD(y, x % y);
}