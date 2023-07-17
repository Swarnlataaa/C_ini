#include <stdio.h>

// Function to calculate the average and percentage of marks
void calculateAverageAndPercentage(int marks1, int marks2, int marks3, float *average, float *percentage)
{
    // Calculate the average
    *average = (marks1 + marks2 + marks3) / 3.0;

    // Calculate the percentage
    *percentage = (*average / 100.0) * 100;
}

int main()
{
    int marks1, marks2, marks3;

    // Input the marks for three subjects
    printf("Enter marks for subject 1: ");
    scanf("%d", &marks1);
    printf("Enter marks for subject 2: ");
    scanf("%d", &marks2);
    printf("Enter marks for subject 3: ");
    scanf("%d", &marks3);

    float average, percentage;

    // Call the calculateAverageAndPercentage function and pass the marks and pointers to the variables
    calculateAverageAndPercentage(marks1, marks2, marks3, &average, &percentage);

    // Print the average and percentage
    printf("Average marks: %.2f\n", average);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
