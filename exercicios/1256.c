#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct celula *seg;
} celula;

celula* push(celula *head, int x) {
    // Alocando um novo nó
    celula *novo = malloc(sizeof(celula));

    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    // Inicializando o nó
    novo->valor = x;
    novo->seg = NULL;

    // Caso a lista esteja vazia, o novo nó será o primeiro
    if (head == NULL) {
        return novo;
    }

    // Adicionando o novo nó ao final da lista
    celula *temp = head;
    while (temp->seg != NULL) {
        temp = temp->seg;
    }
    temp->seg = novo;

    return head;
}

void printar(celula **hashtable, int m) {
    for (int j = 0; j < m; j++) {
        celula *temp = hashtable[j];
        printf("%d ->", j);
        while (temp != NULL) {
            printf(" %d ->", temp->valor);
            temp = temp->seg;
        }
        printf(" \\\n");
    }
}

int main() {
    int n, m, c;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &c);

        celula **hashtable = malloc(m * sizeof(celula*));

        // Inicializando a tabela hash
        for (int j = 0; j < m; j++) {
            hashtable[j] = NULL;
        }

        // Inserindo chaves na tabela hash
        for (int k = 0; k < c; k++) {
            int chave, index;
            scanf("%d", &chave);
            index = chave % m;
            hashtable[index] = push(hashtable[index], chave);
        }

        // Imprimindo a tabela hash
        printar(hashtable, m);

        // Liberando memória das listas encadeadas
        for (int j = 0; j < m; j++) {
            celula *temp = hashtable[j];
            while (temp != NULL) {
                celula *to_free = temp;
                temp = temp->seg;
                free(to_free);
            }
        }

        // Liberando o vetor da tabela hash
        free(hashtable);

        // Adicionando uma linha em branco entre os casos de teste, exceto após o último
        if (i < n - 1) {
            printf("\n");
        }
    }

    return 0;
}