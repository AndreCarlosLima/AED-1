#include<stdio.h>
#include <string.h>

int main(){
    double t,v,s;
    char nome[20];
    scanf("%s", nome);
    scanf("%lf %lf",&s,&v);
    t = s + v*0.15;
    printf("TOTAL = R$ %.2lf\n",t);
    return 0;
}