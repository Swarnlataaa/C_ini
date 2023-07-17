#include <stdio.h>
Struct s
{
    Char name[50];
    Int height;
};
Int main()
{
    Struct s a[5], b[5];
    FILE *fptr;
    Int I;
    Fptr = fopen(“file.txt”, “wb”);
    For(i = 0; i < 5; ++i)
    {
        fflush(stdin);
        printf("Enter name: ");
        gets(a[i].name);
        printf("Enter height: ");
        scanf("%d", &a[i].height);
    }
    fwrite(a, sizeof(a), 1, fptr);
    fclose(fptr);
    fptr = fopen("file.txt", "rb");
    fread(b, sizeof(b), 1, fptr);
    for (i = 0; i < 5; ++i)
    {
        printf("Name: %s\nHeight: %d", b[i].name, b[i].height);
    }
    fclose(fptr);
}