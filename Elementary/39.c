#include <stdio.h>
void check(int);
void main()
{
    int a[10], i;
    clrscr();
    printf(“\n enter the array elements
           :”);
    for (i = 0; i < 10; i++)
    {
        scanf(“% d”, &a[i]);
        check(a[i]);
    }
    void check(int num)
    {
        if (num % 2 == 0)
            printf(“% d is even\n”, num);
        else
            printf(“% d is odd\n”, num);
    }