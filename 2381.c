#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int n, k;
    
    // Lê os valores de n e k
    scanf("%d %d", &n, &k);

    // Matriz para armazenar os nomes (cada nome tem no máximo 20 caracteres + '\0')
    char nomes[n][21];

    // Lê os nomes
    for (int i = 0; i < n; i++) {
        scanf("%s", nomes[i]); // scanf já lê strings corretamente sem armazenar '\n'
    }

    // Ordena os nomes em ordem alfabética
    qsort(nomes, n, sizeof(nomes[0]), compara);

    // Exibe o nome do aluno sorteado (lembrando que os índices começam em 0)
    printf("%s\n", nomes[k - 1]);

    return 0;
}