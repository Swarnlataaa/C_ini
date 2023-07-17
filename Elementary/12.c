#include <stdio.h>
int main()
{
    int m=40,n=20;
    if((m>0)&&(n>0))
    {
        printf("nos are positive");
        if(m>n)
        {
            printf("m is greater than n");
        }
        else{
            printf("m is less than n");
        }
    }
    else{
        printf("nos are negative");
    }
    return 0;
}