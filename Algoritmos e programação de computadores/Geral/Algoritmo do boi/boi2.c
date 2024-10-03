#include <stdio.h>

int main() {
    float peso, maiorP = 0, menorP = 1000000;
    int i = 0;

    do {
        scanf("%f", &peso);

        if (peso > maiorP)
            maiorP = peso;
        if (peso < menorP)
            menorP = peso;
        i++;
    } while (i < 5);

    printf("MAIOR PESO: %.2f\n", maiorP);
    printf("MENOR PESO: %.2f\n", menorP);

    return 0;
}