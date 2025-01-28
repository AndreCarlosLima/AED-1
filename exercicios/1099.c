#include <stdio.h>

int main(){
    int z;
    scanf("%i",&z);
    for(int i=0;i<z;i++){
        int x,y,soma;
        scanf("%i %i",&x,&y);
        if (x>y){
            int h =x;
            x=y;
            y=h;
        }
        if(y==x || y-x==1) printf("0\n");
        else if (y-x==2 && y % 2==1) printf("0\n");
        else{
            soma=0;
            x=x+1;
            while (x<y){
                if (x%2==1) soma=soma+x;
                x=x+1;
            }
            printf("%i\n",soma);
        }
    }
    return 0;
}