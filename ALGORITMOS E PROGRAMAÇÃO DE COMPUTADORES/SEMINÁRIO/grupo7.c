#include <stdio.h>
#define TAM 1000
int indice[TAM];

void ler(int *codigo, char nome[][30], float *media) {
    float nota1, nota2;
    for (int i = 0; i < TAM; i++) {
        scanf("%d,%[^,],%f,%f", &codigo[i], nome[i], &nota1, &nota2);
        media[i] = (nota1 + nota2) / 2.0;
        indice[i] = i;
    }
}

void bubble_sort(int *ind, float *media) {
    int aux;
    for (int i = 1; i < TAM; i++) {
        for (int j = 0; j < TAM - 1; j++) {
            if (media[ind[j]] > media[ind[j + 1]]) {
                aux = ind[j];
                ind[j] = ind[j + 1];
                ind[j + 1] = aux;
            }
        }
    }
}

void imprimir(int *codigo, char nome[][30], float *media) {
    for (int i = 0; media[indice[i]] < 6; i++) {
        printf("%3d, %s, %.2f, Reprovado\n", codigo[indice[i]], nome[indice[i]], media[indice[i]]);
    }
}

int main() {
    float media[TAM];
    int codigo[TAM];
    char nome[TAM][30];

    ler(codigo, nome, media);
    bubble_sort(indice, media);
    imprimir(codigo, nome, media);

    return 0;
}