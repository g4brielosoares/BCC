#include <stdio.h>
#define TAM 100

int main() {
    float vetor[TAM];

    for (int i = 0; i < TAM; i++) {
        scanf("%f", &vetor[i]);

        if (vetor[i] <= 10) {
            printf("A[%d] = %.1f\n", i, vetor[i]);
        }
    }

    return 0;
}