#include<stdio.h>
#include <math.h>

int main(){
    int a,b,c,maior;
    scanf("%i %i %i",&a,&b,&c);
    maior= fmax(a,b);
    maior= fmax(maior,c);
    printf("%i eh o maior\n",maior);
    return 0;
}