#include <stdio.h>

int main(){
    int x,y,cont=0;
    for(int i =0;i<5;i++){
        scanf("%i",&x);
        y= x % 2 ;
        if(y==0) cont ++;
    }
    printf("%i valores pares\n",cont);
    return 0;
}