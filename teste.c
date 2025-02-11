#include <stdio.h>
#include <stdlib.h>

int separaQ(int c,int f, int v[]){
    int pivo=v[f];
    int j= f;
    while(c<j){
        while(c<j && v[c]<pivo){
            c++;
        }
        while(c<j && v[j]>=pivo){
            j--;;
        }
        int temp=v[c];
        v[c]=v[j];
        v[j]=temp;
    }
    v[f]=v[j];
    v[j]=pivo;
    return j;
}

void quicksort(int c, int f,int v[]){
    if(f-c>=1){
        int j=separaQ(c,f,v);
        quicksort(c,j-1,v);
        quicksort(j+1,f,v);
    }

}

void intercala(int c, int f,int q,int v[]){
    int *w=malloc((f-c+1) * sizeof(int));
    int i = c;
    int j = q;
    int k = 0;
    while(i<q && j<f){
        if(v[i]<v[j]){
            w[k++]=v[i++];
        }
        else{
            w[k++]=v[j++];
        }
    }
    while(j<f){
        w[k++]=v[j++]; 
    }
    while(i<q){ 
        w[k++]=v[i++];
    }
    for(int a=c;a<f;a++){
        v[a]=w[a-c];
    }
    free(w);
}

void mergesort(int c, int f,int v[]){
    int q =(c+f)/2;
    if(c<f-1){
        mergesort(c,q,v);
        mergesort(q,f,v);
        intercala(c,f,q,v);
    }

}

int main(){
    int v[7] ={4,10,2,6,9,3,5};

    mergesort(0, 7, v); 
    for(int i=0;i<7;i++){
        printf("%i, ",v[i]);
    }
    return 0;
}