#include <stdio.h>
int main(){
    for(int i=1;i<=9;i=i+2){
        for(int j=7;j>4;j--){
            printf("I=%i J=%i\n",i,j);
        }
    }
    return 0;
}