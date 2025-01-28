#include<stdio.h>

int main(){
    int quantidade,codigo;
    float valor;
    scanf("%d",&codigo);
    scanf("%d",&quantidade);
    switch (codigo)
    {
    case 1:
        valor= quantidade*4;
        break;
    case 2:
        valor= quantidade* 4.5;
        break;
    case 3:
        valor= quantidade*5;
        break;
    case 4:
        valor= quantidade*2;
        break;
    case 5:
        valor= quantidade*1.5;
        break;   
    default:
        break;
    }

    printf("Total: R$ %.2f\n",valor);
    return 0;
}