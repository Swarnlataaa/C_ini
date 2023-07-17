#include <stdio.h>

int main()
{
    int days, years, weeks, remainingDays;

    // Input the number of days
    printf("Enter the number of days: ");
    scanf("%d", &days);

    // Calculate years, weeks, and remaining days
    years = days / 365;
    days %= 365;

    weeks = days / 7;
    days %= 7;

    remainingDays = days;

    // Print the converted values
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d\n", remainingDays);

    return 0;
}
