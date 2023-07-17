#include <stdio.h>

// Define structure
struct DataStruct
{
    int intValue;
    float floatValue;
    char charValue;
};

// Define union
union DataUnion
{
    int intValue;
    float floatValue;
    char charValue;
};

int main()
{
    struct DataStruct dataStruct;
    union DataUnion dataUnion;

    // Print size of structure variable
    printf("Size of structure variable: %zu bytes\n", sizeof(dataStruct));

    // Print size of union variable
    printf("Size of union variable: %zu bytes\n", sizeof(dataUnion));

    return 0;
}
