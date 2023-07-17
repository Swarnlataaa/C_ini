#include <stdio.h>

// Define structure for student
struct Student
{
    char name[50];
    int age;
    float gpa;
};

int main()
{
    struct Student students[3];     // Array of students
    struct Student *ptrStudents[3]; // Array of pointers to students

    int i;

    // Assign pointers to students
    for (i = 0; i < 3; i++)
    {
        ptrStudents[i] = &students[i];
    }

    // Read student data
    for (i = 0; i < 3; i++)
    {
        printf("Enter student %d name: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);

        printf("Enter student %d age: ", i + 1);
        scanf("%d", &(students[i].age));

        printf("Enter student %d GPA: ", i + 1);
        scanf("%f", &(students[i].gpa));

        // Clear the input buffer
        fflush(stdin);
    }

    // Display student data
    for (i = 0; i < 3; i++)
    {
        printf("\nStudent %d Information\n", i + 1);
        printf("Name: %s", ptrStudents[i]->name);
        printf("Age: %d\n", ptrStudents[i]->age);
        printf("GPA: %.2f\n", ptrStudents[i]->gpa);
    }

    return 0;
}
