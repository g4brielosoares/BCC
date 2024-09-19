#include <stdio.h>
#define TAM 1000

int main() {
    int N[TAM], x, j = 0;

    scanf("%d", &x);

    while (j < TAM) {
        for (int i = 0; i < x && j < TAM; i++) {
            N[j] = i;
            printf("N[%d] = %d\n", j, N[j]);
            j++;
        }
    }

    return 0;
}