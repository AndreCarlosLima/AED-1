#include <stdio.h>

int main() {
    int x,y=2;
    scanf("%i",&x);
    while(y<10000){
        printf("%i\n",y);
        y=y+x;
    }
    return 0;
}