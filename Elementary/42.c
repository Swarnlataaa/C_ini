#include <stdio.h>
float average(float a[]);
int main()
{
    float avg, c[] = {23.4, 55, 22.6, 3, 40.5, 18};
    avg = average(c); /* Only name of array is passed as argument. */
    printf("Average age=%.2f", avg);
    return 0;
}
float average(float a[])
{
    int i;
    float avg, sum = 0.0;
    for (i = 0; i < 6; ++i)
    {
        sum += a[i];
    }
    avg = (sum / 6);
    return avg;
}