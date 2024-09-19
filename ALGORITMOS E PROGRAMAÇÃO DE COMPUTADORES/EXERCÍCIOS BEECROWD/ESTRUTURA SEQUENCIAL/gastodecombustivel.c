#include <stdio.h>

int main() {
    int tempoH, Vmedia;
    float litros;
    scanf("%d %d", &tempoH, &Vmedia);

    litros = tempoH * Vmedia / 12.0;

    printf("%.3f\n", litros);

    return 0;
}