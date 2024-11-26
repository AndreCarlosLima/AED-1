#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int pessoa;
    struct celula *seg;
}cel;

cel *inserir_pessoa(cel *cmc,int n){
    cel *novo=malloc(sizeof(cel));
    novo->pessoa = n;
    novo->seg = NULL;

    if (cmc == NULL) {
        return novo; // O novo nó é o pri meiro da lista
    }

    cel *temp = cmc;
    while (temp->seg != NULL) {
        temp = temp->seg;
    }
    temp->seg=novo;
    return cmc;
}

cel *busca_remove(cel *cmc, int z) {
    cel *p = cmc, *prev = NULL;
    while (p != NULL) {
        if (p->pessoa == z) {
            if (prev == NULL) {
                cmc = p->seg;
            } else {
                prev->seg = p->seg;
            }
            free(p);
            break;
        } else {
            prev = p;
            p = p->seg;
        }
    }
    return cmc;
}

void imprimir_pessoas(cel *cmc) {
    cel *temp = cmc;
    while (temp != NULL) {
        printf("%i ", temp->pessoa);  
        temp = temp->seg;
    }
    printf("\n");
}

int main(){
    cel *cmc=NULL;
    int n,x,y,z;

    scanf("%i",&x);
    for(int i=0;i<x;i++){
        scanf("%i",&n);
        cmc=inserir_pessoa(cmc,n);
    }

    scanf(" %i",&y);
    for(int i=0;i<y;i++){
        scanf("%i",&z);
        cmc = busca_remove(cmc,z);
    }    

    imprimir_pessoas(cmc);
    return 0;
}