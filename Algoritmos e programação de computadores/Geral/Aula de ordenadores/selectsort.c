#include <stdio.h>
#define TAM 8

void scan(int *v) {
    for (int x = 0; x < TAM; x++) {
        scanf("%d", &v[x]);
    }
}

void print(int *v) {
    for (int x = 0; x < TAM; x++) {
        printf("%d ", v[x]);
    }
    printf("\n");
}

void sort(int *v) {
    int menor, aux, i, j;
    for (i = 0; i < (TAM - 1); i++) {
        menor = i;
        for (j = (i + 1); j < TAM; j++) {
            if (v[menor] > v[j]) menor = j;
        }
        aux = v[menor];
        v[menor] = v[i];
        v[i] = aux;
    }
}

int main() {   
    int vetor[TAM];

    scan(vetor);
    print(vetor);
    sort(vetor);
    print(vetor);

    return 0;
}