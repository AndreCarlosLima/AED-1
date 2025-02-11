#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "mergesort.h"
#include "insertionsort.h"

#define TAM 30000

int main(){
    int* vetorm = malloc(TAM * sizeof(int));
    int* vetori = malloc(TAM * sizeof(int));
    if (vetorm == NULL || vetori == NULL) {
        fprintf(stderr, "Erro de alocação de memória!\n");
        return 1;
    }
    clock_t tm,ti;
    srand((unsigned)time(NULL));

    for(int i=0;i<TAM;i++){
        vetorm[i] = rand() % TAM;
    }

    tm = clock(); 
    Mergesort(0,TAM,vetorm);
    tm = clock() - tm;  

    printf("Tempo de execucao mergesort: %lf ms\n", ((double)tm)/((CLOCKS_PER_SEC/1000)));

    for(int i=0;i<TAM;i++){
        vetori[i] = rand() % TAM;
    }

    ti = clock(); 
    Insertionsort(TAM,vetori);
    ti = clock() - ti;  

    printf("Tempo de execucao insertionsort: %lf ms\n", ((double)ti)/((CLOCKS_PER_SEC/1000))); 
 

    free(vetori);
    free(vetorm);
    return 0;
}