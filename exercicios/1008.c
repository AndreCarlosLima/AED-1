#include<stdio.h>

int main(){
    int n,h;
    float sh,st;
    scanf("%i %i %f",&n,&h,&sh);
    st=sh*h;
    printf("NUMBER = %i\nSALARY = U$ %.2f",n,st);
    return 0;
}