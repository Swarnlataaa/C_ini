#include <stdio.h>

// Function to determine if a year is a leap year or not
int isLeapYear(int year)
{
    // Leap year conditions:
    // 1. Year should be divisible by 4
    // 2. Year should not be divisible by 100, except if it is divisible by 400

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1; // Leap year
            }
            else
            {
                return 0; // Not a leap year
            }
        }
        else
        {
            return 1; // Leap year
        }
    }
    else
    {
        return 0; // Not a leap year
    }
}

int main()
{
    int year;

    // Input the year
    printf("Enter a year: ");
    scanf("%d", &year);

    // Check if the year is a leap year using the isLeapYear function
    if (isLeapYear(year))
    {
        printf("%d is a leap year.\n", year);
    }
    else
    {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
