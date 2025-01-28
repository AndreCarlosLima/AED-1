#include<stdio.h>

int main(){
    int n,q;
    float vu,vt=0;
    for(int i=0;i<2;i++){
        scanf("%i %i %f",&n,&q,&vu);
        vt=vt+ (float)q*vu;
    }
    printf("VALOR A PAGAR: R$ %.2f\n",vt);
}