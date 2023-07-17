#include <stdio.h>
void main()
{
    int array[10];
    int i, j, temp;
    printf("enter the element of an array \n");
    for (i = 0; i < 10; i++)
        scanf("%d", &array[i]);
    printf("Alternate elements of a given array \n");
    for (i = 0; i < 10; i += 2)
        printf("%d\n", array[i]);
}