#include <stdio.h>

int main(){
    int idade, soma=0,cont=0;
    float im;
    scanf("%i",&idade);
    while(idade>=0){
        soma=soma+idade;
        cont++;
        scanf("%i",&idade);
    }
    im=(float)soma/cont;
    printf("%.2f\n",im);
    return 0;
}