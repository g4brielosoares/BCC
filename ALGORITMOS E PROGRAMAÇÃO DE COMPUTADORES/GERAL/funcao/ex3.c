#include <stdio.h>
const int TAM = 5;

void media_aluno(float v[], float u[], float w[]) {
    for (int i = 0; i < 5; i++) {
        w[i] = (v[i] + u[i]) / 2.0;
    }
}

float media_sala(float v[]) {
    float media = 0, soma = 0;

    for (int i = 0; i < 5; i++) {
        soma += v[i];
    }
    media = soma / 5.0;

    return media;
}

void leia_nota(float v[]) {
    for (int i = 0; i < 5; i++) {
        scanf("%f", &v[i]);
    }
}

int main() {
    float a[TAM], b[TAM], c[TAM];

    leia_nota(a);
    leia_nota(b);
    media_aluno(a, b, c);
    printf("A media da sala e %.1f", media_sala(c));

    return 0;
}