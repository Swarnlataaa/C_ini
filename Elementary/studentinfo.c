#include <stdio.h>

// Define structure for student
struct Student
{
    char name[50];
    int age;
    float gpa;
};

// Function to initialize student information
void initializeStudent(struct Student *student)
{
    printf("Enter student name: ");
    fgets(student->name, sizeof(student->name), stdin);

    printf("Enter student age: ");
    scanf("%d", &(student->age));

    printf("Enter student GPA: ");
    scanf("%f", &(student->gpa));
}

// Function to print student information
void printStudent(const struct Student *student)
{
    printf("\nStudent Information\n");
    printf("Name: %s", student->name);
    printf("Age: %d\n", student->age);
    printf("GPA: %.2f\n", student->gpa);
}

int main()
{
    struct Student student;
    struct Student *ptrStudent = &student;

    // Initialize student information
    initializeStudent(ptrStudent);

    // Print student information
    printStudent(ptrStudent);

    return 0;
}
