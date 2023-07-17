#include <stdio.h>

int main()
{
    int totalHours;
    int wage = 0;
    int wageEarned;

    // Input total hours worked
    printf("Enter the total hours worked: ");
    scanf("%d", &totalHours);

    // Calculate wage based on time worked
    if (totalHours <= 10)
    {
        wage = totalHours * 60;
    }
    else if (totalHours <= 16)
    {
        wage = (10 * 60) + ((totalHours - 10) * 15);
    }
    else if (totalHours <= 20)
    {
        wage = (10 * 60) + (6 * 15) + ((totalHours - 16) * 18);
    }
    else if (totalHours > 20)
    {
        wage = (10 * 60) + (6 * 15) + (4 * 18) + ((totalHours - 20) * 25);
    }

    // Print wage earned
    printf("Total Hours Worked: %d\n", totalHours);
    printf("Wage Earned: Rs %d\n", wage);

    return 0;
}
