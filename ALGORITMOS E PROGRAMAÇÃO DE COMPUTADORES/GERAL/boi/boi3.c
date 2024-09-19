#include <stdio.h>

int main() {
    float peso, maiorP = 0, menorP = 1000000;

    for (int i = 0; i < 5; i++) {
        scanf("%f", &peso);

        if (peso > maiorP)
            maiorP = peso;
        if (peso < menorP)
            menorP = peso;
    }

    printf("MAIOR PESO: %.2f\n", maiorP);
    printf("MENOR PESO: %.2f\n", menorP);

    return 0;
}