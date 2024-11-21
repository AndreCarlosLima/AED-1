<<<<<<< HEAD
#include <stdio.h>
 
int main() {
    int dias, idadeAno, idadeMes, idadeDia;
    scanf("%d", &dias);
    idadeAno = dias/365;
    idadeMes = (dias%365)/30;
    idadeDia = (dias%365)%30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", idadeAno, idadeMes, idadeDia);
 
    return 0;
=======
#include <stdio.h>
 
int main() {
    int dias, idadeAno, idadeMes, idadeDia;
    scanf("%d", &dias);
    idadeAno = dias/365;
    idadeMes = (dias%365)/30;
    idadeDia = (dias%365)%30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", idadeAno, idadeMes, idadeDia);
 
    return 0;
>>>>>>> 8ad95095f182f6b576c579ba9b1983993dc3d53b
}