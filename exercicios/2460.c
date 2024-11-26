#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int pessoa;
    struct celula *seg;
}cel;

cel *inserir_pessoa(cel **cmc,cel *fim,int n){
    cel *novo=malloc(sizeof(cel));
    novo->pessoa = n;
    novo->seg = NULL;

    if (*cmc == NULL) {
        *cmc=novo;
        return novo; // O novo nó é o pri meiro da lista
    }

    fim->seg=novo;
    return novo;
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
        printf("%d", temp->pessoa); // Imprime o valor sem espaço no final
        temp = temp->seg;
        if (temp != NULL) {
            printf(" "); // Apenas adiciona espaço se não for o último elemento
        }
    }
    printf("\n"); // Adiciona uma quebra de linha ao final
}

int main(){
    cel *cmc=NULL;
    cel *p;
    int n,x,y,z;

    scanf("%i",&x);
    for(int i=0;i<x;i++){
        scanf("%i",&n);
        p=inserir_pessoa(&cmc,p,n);
    }

    scanf(" %i",&y);
    for(int i=0;i<y;i++){
        scanf("%i",&z);
        cmc = busca_remove(cmc,z);
    }    

    imprimir_pessoas(cmc);
    return 0;
}
