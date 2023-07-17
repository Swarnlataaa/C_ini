#include <stdio.h>

// Define structure for time
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

// Function to display time
void displayTime(const struct Time *time)
{
    printf("%02d:%02d:%02d\n", time->hours, time->minutes, time->seconds);
}

// Function to add two times
struct Time addTime(const struct Time *t1, const struct Time *t2)
{
    struct Time result;
    int totalSeconds = (t1->hours * 3600) + (t1->minutes * 60) + t1->seconds + (t2->hours * 3600) + (t2->minutes * 60) + t2->seconds;

    result.hours = totalSeconds / 3600;
    result.minutes = (totalSeconds % 3600) / 60;
    result.seconds = (totalSeconds % 3600) % 60;

    return result;
}

// Function to subtract two times
struct Time subtractTime(const struct Time *t1, const struct Time *t2)
{
    struct Time result;
    int totalSeconds = (t1->hours * 3600) + (t1->minutes * 60) + t1->seconds - ((t2->hours * 3600) + (t2->minutes * 60) + t2->seconds);

    if (totalSeconds < 0)
    {
        totalSeconds += 86400; // Add 24 hours (in seconds) to handle negative result
    }

    result.hours = totalSeconds / 3600;
    result.minutes = (totalSeconds % 3600) / 60;
    result.seconds = (totalSeconds % 3600) % 60;

    return result;
}

int main()
{
    struct Time time1, time2;

    // Read time 1
    printf("Enter time 1 (hours minutes seconds): ");
    scanf("%d %d %d", &(time1.hours), &(time1.minutes), &(time1.seconds));

    // Read time 2
    printf("Enter time 2 (hours minutes seconds): ");
    scanf("%d %d %d", &(time2.hours), &(time2.minutes), &(time2.seconds));

    // Display time 1 and time 2
    printf("\nTime 1: ");
    displayTime(&time1);

    printf("Time 2: ");
    displayTime(&time2);

    // Add time 1 and time 2
    struct Time sum = addTime(&time1, &time2);
    printf("\nSum of times: ");
    displayTime(&sum);

    // Subtract time 2 from time 1
    struct Time difference = subtractTime(&time1, &time2);
    printf("Difference of times: ");
    displayTime(&difference);

    return 0;
}
