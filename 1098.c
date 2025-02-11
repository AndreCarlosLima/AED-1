#include <stdio.h>
int main(){
    float x=0,j;
    for(float i=0;i<=2.1;i=i+0.20){
        for(int k=1;k<=3;k++){
            j=x+k;
            if(i==0) printf("I=%.0f J=%.0f\n",i,j);
            else if (i > 0.99 && i < 1.01) printf("I=%.0f J=%.0f\n",i,j);
            else if (i > 1.99 && i < 2.01) printf("I=%.0f J=%.0f\n",i,j);
            else printf("I=%.1f J=%.1f\n",i,j);
        }
        x=x+0.2;
    }
    return 0;
}