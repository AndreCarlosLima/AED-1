<<<<<<< HEAD
#include<stdio.h>
#include<math.h>
#include <stdbool.h> 

int alterar_posicaoy(int y, char instrucao){
    if(instrucao=='C' ){
        y++;
        return y;
    }
    if(instrucao=='B' ){
        y--;
        return y;
    }
    return y;
}

int alterar_posicaox(int x, char instrucao){
    if(instrucao=='D' ){
        x++;
        return x;
    }
    if(instrucao=='E' ){
        x--;
        return x;
    }
    return x;
}

bool verificacao(int k,int xf,int yf,int x, int y){
    int distancia_quadrada=sqrt(pow(xf-x,2)+pow(yf-y, 2));
    return distancia_quadrada<=k*k;
}

int main(){
    char instrucao;
    int n,k,xf,yf;
    scanf("%i",&n);
    scanf("%i",&k);
    scanf("%i",&xf);
    scanf("%i",&yf);

    int x=0,y=0,cont=0;

    if (!verificacao(k, xf, yf, x, y)) {
        printf("Trap 1\n");
        return 0;
    }

    for (int i=0;i<n;i++){
        cont++;
        scanf(" %c",& instrucao);
        if (instrucao=='C'|| instrucao=='B'){
            y=alterar_posicaoy(y,instrucao);
        }
        else if (instrucao=='E'|| instrucao=='D'){
            x=alterar_posicaox(x,instrucao);
        }
        else{
            printf("instrucao errada\n");
            continue;
        }

        if (!verificacao(k, xf, yf, x, y)) {
            printf("Trap %d\n", cont);
            return 0;
        }

        if(i==n-1) printf("Sucesso\n");
    }
    return 0;
=======
#include<stdio.h>
#include<math.h>
#include <stdbool.h> 

int alterar_posicaoy(int y, char instrucao){
    if(instrucao=='C' ){
        y++;
        return y;
    }
    if(instrucao=='B' ){
        y--;
        return y;
    }
    return y;
}

int alterar_posicaox(int x, char instrucao){
    if(instrucao=='D' ){
        x++;
        return x;
    }
    if(instrucao=='E' ){
        x--;
        return x;
    }
    return x;
}

bool verificacao(int k,int xf,int yf,int x, int y){
    int distancia_quadrada=sqrt(pow(xf-x,2)+pow(yf-y, 2));
    return distancia_quadrada<=k*k;
}

int main(){
    char instrucao;
    int n,k,xf,yf;
    scanf("%i",&n);
    scanf("%i",&k);
    scanf("%i",&xf);
    scanf("%i",&yf);

    int x=0,y=0,cont=0;

    if (!verificacao(k, xf, yf, x, y)) {
        printf("Trap 1\n");
        return 0;
    }

    for (int i=0;i<n;i++){
        cont++;
        scanf(" %c",& instrucao);
        if (instrucao=='C'|| instrucao=='B'){
            y=alterar_posicaoy(y,instrucao);
        }
        else if (instrucao=='E'|| instrucao=='D'){
            x=alterar_posicaox(x,instrucao);
        }
        else{
            printf("instrucao errada\n");
            continue;
        }

        if (!verificacao(k, xf, yf, x, y)) {
            printf("Trap %d\n", cont);
            return 0;
        }

        if(i==n-1) printf("Sucesso\n");
    }
    return 0;
>>>>>>> 8ad95095f182f6b576c579ba9b1983993dc3d53b
}