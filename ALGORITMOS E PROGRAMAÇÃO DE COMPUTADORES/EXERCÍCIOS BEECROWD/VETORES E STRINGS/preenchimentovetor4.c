#include <stdio.h>
#define TAM 5

int main() {
    int impar[TAM], par[TAM], aux = 0, contador_par = 0, contador_impar = 0;

    for (int i = 0; i < (TAM * 3); i++) {
        scanf("%d", &aux);
        
        if ((aux % 2) == 0) {
            par[contador_par] = aux;
            contador_par++;

            if (contador_par == TAM) {
                for (int j = 0; j < TAM; j++) {
                    printf("par[%d] = %d\n", j, par[j]);
                    par[j] = 0;
                    contador_par = 0;
                }
            }
        } else if ((aux % 2) != 0) {
            impar[contador_impar] = aux;
            contador_impar++;

            if (contador_impar == TAM) {
                for (int j = 0; j < TAM; j++) {
                    printf("impar[%d] = %d\n", j, impar[j]);
                    impar[j] = 0;
                    contador_impar = 0;
                }
            }
        }
    }

    for (int i = 0; i < contador_impar; i++) {
        printf("impar[%d] = %d\n", i, impar[i]);
    }

    for (int i = 0; i < contador_par; i++) {
        printf("par[%d] = %d\n", i, par[i]);
    }

    return 0;
}