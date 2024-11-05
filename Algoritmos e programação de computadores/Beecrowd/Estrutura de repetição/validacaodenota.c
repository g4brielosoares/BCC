#include <stdio.h>

int main() {
    float avalia1, avalia2;

    do {
        scanf("%f", &avalia1);

        if (avalia1 < 0 || avalia1 > 10) {
        printf("nota invalida\n");
        }
    } while (avalia1 > 10 || avalia1 < 0);
    
    do {
        scanf("%f", &avalia2);

        if (avalia2 < 0 || avalia2 > 10) {
        printf("nota invalida\n");
        }
    } while (avalia2 > 10 || avalia2 < 0);
    
    printf("media = %.2f\n", (avalia1 + avalia2) / 2.0);
    
    return 0;
}