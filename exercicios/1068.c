#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no {
    char conta[1000];
    struct no *seg;
} cel;


void verificar(char conta[]){
    int x = 0, y = 0;
    int check = 1;
    for (int i = 0; i < strlen(conta); i++) {
        if(conta[i]==')'){
            x++;
        }
        else if (conta[i]=='('){
            y++;
        }
        if(x>y){
            check=0;
            break;
        } 
    }
    if(check && x==y){
        printf("correct\n");
    }
    else{
        printf("incorrect\n"); 
    }
}

void inserir_conta(cel **fila, char conta[]){
    cel *aux;
    cel *novo=malloc(sizeof(cel));

    strcpy(novo->conta,conta);
    novo->seg=NULL;

    if(*fila==NULL){
        *fila=novo;
    }
    else{
        aux=*fila;
        while (aux->seg!=NULL){
            aux=aux->seg;
        }
        aux->seg=novo;
    }   
}


int main(){
    cel *fila=NULL;
    char expressao[1001];

    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        expressao[strcspn(expressao, "\n")] = '\0'; // Remove o '\n'
        if (strlen(expressao) > 0) { // Ignora entradas vazias
            inserir_conta(&fila, expressao);
        }
    }

    cel *aux=fila;
    while(aux!=NULL){
        verificar(aux->conta);
        aux=aux->seg;
    }

    return 0;
}
