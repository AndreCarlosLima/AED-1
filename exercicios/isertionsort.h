#include <stdio.h>

void Insertionsort (int n, int v[]) {
    int x,j,i;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--){
            v[i+1] = v[i];
        }
        v[i+1] = x;
    }
}