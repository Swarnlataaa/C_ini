#include <stdio.h>
int power(int, int);
void main()
{
    int n, m, k;
    printf("Enter the value of n and m");
    scanf("% d % d", &n, &m);
    k = power(n, m);
printf("The value of n for n=%d and m=%d is %d",n,m,k);
}
int power(int x, int y)
{
if (y == 0)
{
    return 1;
}
else
{
    return (x * power(x, y - 1));
}
}