#include <stdio.h>

int main(){
    float x,y,m;
    scanf("%f",&x);
    while (x>10 || x<0){
       printf("nota invalida\n");
       scanf("%f",&x); 
    }
    scanf("%f",&y);
    while (y>10 || y<0){
       printf("nota invalida\n");
       scanf("%f",&y); 
    }
    m=(x+y)/2;
    printf("media = %.2f\n",m);
    return 0;
}