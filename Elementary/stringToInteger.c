#include <stdio.h>
#include <stdlib.h>

int stringToInteger(const char *str)
{
    return atoi(str);
}

int main()
{
    char str[20];

    printf("Enter a string: ");
    scanf("%s", str);

    int num = stringToInteger(str);

    printf("Converted integer: %d\n", num);

    return 0;
}
