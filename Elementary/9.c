#include <stdio.h>
int main(){
    int no;
    printf("Enter a no: ");
    scanf("%d",&no);
    if(no<0){
        printf("no entered is negative");
        no=-no;
    }
    printf("value of no is %d \n",no);
    return 0;
}