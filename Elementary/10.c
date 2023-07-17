#include <stdio.h>
int main()
{
    int a,b;
    float c;
    printf("Enter two no's: ");
    scanf("%d%d",&a,&b);
    if(b==0){
        printf("Division is not possible");

    }
    c=a/b;
    printf("quotient is %f \n",c);
    return 0;
}