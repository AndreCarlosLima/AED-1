#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "mergesort.h"
#include "insertionsort.h"
#include "quicksort.h"


int main(){
    printf("Tempo de execucao mergesort:\n");
    for(int TAM=20000;TAM<=400000;TAM+=20000){
        int* vetorm = malloc(TAM * sizeof(int));
        if (vetorm == NULL) {
            fprintf(stderr, "Erro de alocação de memória!\n");
            return 1;
        }
        clock_t tm;
        srand((unsigned)time(NULL));

        for(int i=0;i<TAM;i++){
            vetorm[i] = rand() % TAM;
        }
        float k=0;
        for(int j=0;j<3;j++){
            tm = clock(); 
            Mergesort(0,TAM,vetorm);
            tm = clock() - tm;  
            k= k+tm;
        }
        tm=k/3;
        printf("%lf ms\n", ((double)tm)/((CLOCKS_PER_SEC/1000)));
        free(vetorm);
    }


    printf("Tempo de execucao Quicksort:\n");
    for(int TAM=20000;TAM<=400000;TAM+=20000){
        int* vetorm = malloc(TAM * sizeof(int));
        if (vetorm == NULL) {
            fprintf(stderr, "Erro de alocação de memória!\n");
            return 1;
        }
        clock_t tm;
        srand((unsigned)time(NULL));

        for(int i=0;i<TAM;i++){
            vetorm[i] = rand() % TAM;
        }

        tm = clock(); 
        Quicksort(0,TAM-1,vetorm);
        tm = clock() - tm;  

        printf("%lf ms\n", ((double)tm)/((CLOCKS_PER_SEC/1000)));
        free(vetorm);
    }


    printf("Tempo de execucao Insertionsort:\n");
    for(int TAM=20000;TAM<=400000;TAM+=20000){
        int* vetorm = malloc(TAM * sizeof(int));
        if (vetorm == NULL) {
            fprintf(stderr, "Erro de alocação de memória!\n");
            return 1;
        }
        clock_t tm;
        srand((unsigned)time(NULL));

        for(int i=0;i<TAM;i++){
            vetorm[i] = rand() % TAM;
        }

        tm = clock(); 
        Insertionsort(TAM,vetorm);
        tm = clock() - tm;  


        printf("%lf ms\n", ((double)tm)/((CLOCKS_PER_SEC/1000)));
        free(vetorm);
    }


    return 0;
}