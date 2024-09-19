#include <stdio.h>

float notaaluno() {
    float media, n, soma = 0;
    
    for (int i = 0; i < 4; i++) {
        scanf("%f", &n);
        soma = soma + n;
    }
    media = soma / 4.0;

    return media;
}

int main() {
    float media[10] = {0};
    for (int i = 0; i < 10; i++) {
        media[i] = notaaluno();
        printf("Media do %do aluno: %.1f", i + 1, media[i]);
    }

    return 0;
}