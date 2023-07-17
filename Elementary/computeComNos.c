#include <stdio.h>

// Define structure for complex number
struct Complex
{
    float real;
    float imaginary;
};

// Function to read complex number
void readComplex(struct Complex *c)
{
    printf("Enter real part: ");
    scanf("%f", &(c->real));

    printf("Enter imaginary part: ");
    scanf("%f", &(c->imaginary));
}

// Function to display complex number
void displayComplex(const struct Complex *c)
{
    printf("%.2f + %.2fi\n", c->real, c->imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(const struct Complex *c1, const struct Complex *c2)
{
    struct Complex result;
    result.real = c1->real + c2->real;
    result.imaginary = c1->imaginary + c2->imaginary;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtractComplex(const struct Complex *c1, const struct Complex *c2)
{
    struct Complex result;
    result.real = c1->real - c2->real;
    result.imaginary = c1->imaginary - c2->imaginary;
    return result;
}

int main()
{
    struct Complex num1, num2;

    printf("Enter first complex number:\n");
    readComplex(&num1);

    printf("Enter second complex number:\n");
    readComplex(&num2);

    printf("\nFirst complex number: ");
    displayComplex(&num1);

    printf("Second complex number: ");
    displayComplex(&num2);

    // Perform addition
    struct Complex sum = addComplex(&num1, &num2);
    printf("\nSum of the complex numbers: ");
    displayComplex(&sum);

    // Perform subtraction
    struct Complex difference = subtractComplex(&num1, &num2);
    printf("Difference of the complex numbers: ");
    displayComplex(&difference);

    return 0;
}
