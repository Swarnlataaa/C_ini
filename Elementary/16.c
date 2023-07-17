#include <stdio.h>
int main()
{
    int sum =0,num;
    do
    {
        printf("Enter a number\n");
        scanf("%d",&num);
        sum+=num;
        /* code */
    } while (num!=0);
    printf("sum =%d",sum);
    return 0;
    
}