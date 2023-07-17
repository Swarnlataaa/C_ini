#include <stdio.h>
int main()
{
    char grade;
    printf("Enter the grade");
    scanf("%c",&grade);
    switch(grade)
    {
        case 'A' :printf("Outstanding!\n");
        case 'B' :printf("Excellent!\n");
        case 'C':
            printf("Well done\n");
        case 'D':
            printf("You passed\n");
        case 'F':
            printf("Better try again\n");
        default:
            printf("Inavlid grade\n");
    }
    printf("Your grade is %c\n",grade);
    return 0;
}