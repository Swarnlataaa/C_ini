#include <stdio.h>
main()
{
    int i, a[6] = {1, 2, 3, 4, 5, 6};
    func(a);
    printf(“contents of array
           :”);
    for (i = 0; i < 6; i++)
        printf(“% d”, a[i]);
    printf(”\n”);
}
func(int val[])
{
    int sum = 0, i;
    for (i = 0; i < 6; i++)
    {
        val[i] = val[i] * val[i];
        sum += val[i];
    }
    printf(“the sum of squares
           : % d”, sum);
}