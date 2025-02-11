#include<stdio.h>

int main(){
    int max=0,pos,x;
    for(int i=1;i<=100;i++){
        scanf("%d",&x);
        if (x>max){
            max=x;
            pos=i;
        }
    }
    printf("%i\n",max);
    printf("%i\n",pos);
    return 0;
}