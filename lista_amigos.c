#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

struct cel{
    char amigo [MAX];
    struct cel *seg;
};
typedef struct cel celula;


celula *buscar_amigo(celula *cmc, const char *nome) {
    if (cmc == NULL || cmc->seg == NULL) {
        printf("Nenhum amigo na lista.\n");
        return NULL;
    }


    celula *temp = cmc->seg;  // Começa da lista, após a cabeça

    celula *anterior = cmc;

    while (temp != NULL) {
        if (strcmp(temp->amigo, nome) == 0) {  // Se encontrar o nome
            return anterior;  // Retorna o ponteiro para o nó encontrado
        }
        anterior = temp;  // Atualiza o ponteiro anterior
        temp = temp->seg;  // Avança para o próximo nó
    }
    return NULL;  // Retorna NULL se o nome não for encontrado
}



celula *inserir_amigo(celula *cmc, char *nome){
    nome[strcspn(nome, "\n")] = '\0';

    celula *novo= malloc(sizeof(celula));

    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);  // Sai do programa se não conseguir alocar memória
    }

    strncpy(novo->amigo, nome, MAX - 1);
    novo->amigo[MAX - 1] = '\0';  // Garante que a string seja nula-terminada

    novo->seg=cmc->seg;
    cmc->seg = novo;

    return novo;
}

void imprimir_amigos(celula *cmc) {
    celula *temp = cmc->seg;
    if (temp != NULL) {
        printf("%s", temp->amigo);  // Imprime o primeiro amigo sem espaço
        temp = temp->seg;
    }
    while (temp != NULL) {
        printf(" %s", temp->amigo);  // Imprime o resto com um espaço antes
        temp = temp->seg;
    }
    printf("\n");
}


int main(){
    celula cmc;
    celula *j;
    j=&cmc;
    cmc.seg =NULL;
    

    char input[100];  // Variável para armazenar a linha de entrada
    char *nome;       // Ponteiro para armazenar cada nome individual

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  

    // Usa strtok para dividir a string em tokens (neste caso, nomes separados por espaço)
    nome = strtok(input," ");

    // Enquanto houver mais tokens, adiciona eles na lista
    celula*p= &cmc;
    while (nome != NULL) {
        p=inserir_amigo(p,nome);
        nome = strtok(NULL," ");  
    }

    char input2[100];  // Variável para armazenar a 2ªlinha de entrada
    fgets(input2, sizeof(input2), stdin);
    input2[strcspn(input2, "\n")] = '\0'; 

    char input3[MAX];
    fgets(input3, sizeof(input3), stdin);
    input3[strcspn(input3, "\n")] = '\0';


    if(strcmp(input3, "nao") != 0){
        celula *busca=buscar_amigo(j,input3);

        if(busca!=NULL){
            nome = strtok(input2, " ");
            while (nome != NULL) {
                busca=inserir_amigo(busca,nome);
                nome = strtok(NULL," ");  
            }
        }
    } 
    else{
        nome = strtok(input2, " ");
        while (nome != NULL) {
        p=inserir_amigo(p,nome);
        nome = strtok(NULL, " ");  
        }
    }
    
    imprimir_amigos(j);

    return 0;
}

