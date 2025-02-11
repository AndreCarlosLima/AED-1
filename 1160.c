#include <stdio.h>

int main() {
    int t, pa, pb, cont;
    double g1, g2;

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);

        g1 = (g1 / 100.0) + 1.0;
        g2 = (g2 / 100.0) + 1.0;
        cont = 0;

        while (pa <= pb) {
            pa = (int)(pa * g1);
            pb = (int)(pb * g2);
            cont++;

            if (cont > 100) {
                printf("Mais de 1 seculo.\n");
                break;
            }
        }

        if (cont <= 100) {
            printf("%d anos.\n", cont);
        }
    }

    return 0;
}