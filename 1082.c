///ex 1082 beecrowd///

#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int w;
    struct no *next;
} link;

typedef struct graph{
    int V;
    int A;
    link **adj;
}*Graph;

Graph GraphInit(int v){
    Graph G = malloc(sizeof (Graph*));
    G->V=v;
    G->A=0;
    G->adj= malloc(v* sizeof (link));
    for(int i=0;i<v;i++){
        G->adj[i]=NULL;
    }
    return G;
}


link *NEWnode( int w, link *next) { 
   link *a = malloc( sizeof (link));
   a->w = w; 
   a->next = next;     
   return a;                         
}

void isertarc(Graph G,int v,int w){
    for(link *a = G->adj[v];a!=NULL;a=a->next){
        if(a->w==w) return;
    }
    G->adj[v]= NEWnode( w, G->adj[v]);
    G->A++;

    for(link *a = G->adj[w];a!=NULL;a=a->next){
        if(a->w==v) return;
    }
    G->adj[w]= NEWnode( v, G->adj[w]);
    G->A++;
    
}


void DFS(Graph G,int V,int *visitado,int componentes){
    link *temp=G->adj[V];
    visitado[V]=componentes;
    while (temp!= NULL){
        if (!visitado[temp->w]){
            DFS(G,temp->w,visitado,componentes);
        }
        temp=temp->next;
    }
}

int conexo(Graph G){
    int *visitado=malloc(G->V * sizeof(int));

    for (int i = 0; i < G->V; i++) {
        visitado[i] = 0;  // Inicializa todos como não visitados
    }
    int chave=0;
    int componentes=1;
    DFS(G,chave,visitado,componentes);
    for(int i=0;i<G->V;i++){
        if(visitado[i]==0){
            componentes++;
            chave=i;
            DFS(G,chave,visitado,componentes);
        }
    }
    char vertice;
    for(int j=1;j<componentes+1;j++){
        for(int k=0;k<G->V;k++){
            if(visitado[k]==j){
                vertice= k +'a';
                printf("%c,",vertice);
            } 
        }
        printf("\n");
    }
    free(visitado);
    return componentes;
}




int main(){
    int n;
    scanf("%i",&n);
    for(int k=1;k<n+1;k++){
        int v,a;
        scanf("%i %i", &v, &a);

        Graph G = GraphInit(v);

        char o,d;
        for(int i=0;i<a;i++){
            scanf(" %c %c", &o, &d);
            isertarc(G, o-'a', d-'a');
        }

        printf("case #%i:\n",k);
        int componentes=conexo(G);
        printf("%i connected components\n",componentes);
        printf("\n");
    }
    return 0;
}


