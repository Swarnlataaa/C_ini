#include <stdio.h>

void function()
{
    auto int num = 10; // The 'auto' keyword is optional since it's the default storage class

    printf("Value of num inside function: %d\n", num);
    num++;
    printf("Value of num inside function after increment: %d\n", num);
}

int main()
{
    auto int num = 5; // The 'auto' keyword is optional since it's the default storage class

    printf("Value of num inside main: %d\n", num);
    num++;
    printf("Value of num inside main after increment: %d\n", num);

    function();

    printf("Value of num after function call: %d\n", num);

    return 0;
}
