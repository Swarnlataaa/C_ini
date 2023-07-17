#include <stdio.h>
int main(){
    int n,i,sum=0;
    printf("enter the limit: ");
    scanf("%d",&n);
    
    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    printf("Sum of N natural numbers is: %d", sum);
}
