#include<stdio.h>
#include <math.h>

int main(){
    double a,b,c,x;
    scanf("%lf %lf %lf",&a,&b,&c);
    x=a*c/2;
    printf("TRIANGULO: %.3lf\n",x);
    x=3.14159 * pow(c,2);
    printf("CIRCULO: %.3lf\n",x);
    x=(a+b)*c/2;
    printf("TRAPEZIO: %.3lf\n",x);
    x=pow(b,2);
    printf("QUADRADO: %.3lf\n",x);
    x=a*b;
    printf("RETANGULO: %.3lf\n",x);
    return 0;
}