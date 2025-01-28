#include <stdio.h>

int main() {
    int x;
    scanf("%i",&x);
    if (x%2==0) x=x+1;
    for (int i=0;i<6;i++){
        printf("%i\n",x);
        x=x+2;
    }
    return 0;
}