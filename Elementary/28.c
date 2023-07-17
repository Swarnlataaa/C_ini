#include <stdio.h>
void main()
{
    int n, s;
    printf("Enter a number");
    scanf("% d", &n);
    s = sum(n);
    printf("Sum of numbers from 1 to % d is % d", n, s);
}
int sum(int m) int r;
if (m == 1)
    return (1);
else
    r = m + sum(m - 1); /*Recursive Call*/
return r;
}