#include <stdio.h>
#include <conio.h>
#include <math.h>
void main()
{
    int number = 0, digit[10], numofdigits, i;
    clrscr();
    printf(“\n Enter the number of digits
           :”);
    scanf(“% d”, &numofdigits);
    for (i = 0; i < numofdigits; i++)
    {
        printf(“\n Enter the % d th digit
               :”, i);
        scanf(“% d”, &digit[i]);
    }
    i = 0;
    while (i < numofdigits)
    {
        number = number + digit[i] * pow(10, i)
                                         i++;
    }
    printf(“\n The number is
           : % d”, number);
    getch();
}