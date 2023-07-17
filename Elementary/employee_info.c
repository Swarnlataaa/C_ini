#include <stdio.h>

// Define structure for employee
struct Employee
{
    char name[50];
    int age;
    float salary;
};

int main()
{
    struct Employee emp;

    // Read employee information
    printf("Enter employee name: ");
    fgets(emp.name, sizeof(emp.name), stdin);

    printf("Enter employee age: ");
    scanf("%d", &emp.age);

    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    // Clear the input buffer
    fflush(stdin);

    // Display employee information
    printf("\nEmployee Information\n");
    printf("Name: %s", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);

    return 0;
}
