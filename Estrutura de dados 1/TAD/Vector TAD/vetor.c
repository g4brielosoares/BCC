#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"

struct vetor {
    int a, b;
};

Vetor *criar_vetor(int a, int b) {
    Vetor *v = malloc(sizeof(Vetor));

    setar_vetor(v, a, b);

    return v;
}

void remover_vetor(Vetor **v) {
    free(*v);
}

void setar_vetor(Vetor *v, int a, int b) {
    v->a = a;
    v->b = b;
}

void obter_vetor(Vetor *v, int *a, int *b) {
    *a = v->a;
    *b = v->b;
}

Vetor *somar_vetores(Vetor *v1, Vetor *v2) {
    Vetor *vSoma = criar_vetor(0, 0);

    setar_vetor(vSoma, v1->a + v2->a, v1->b + v2->b);

    return vSoma;
}

Vetor *subtrair_vetores(Vetor *v1, Vetor *v2) {
    Vetor *vSub = criar_vetor(0, 0);

    setar_vetor(vSub, v1->a - v2->a, v1->b - v2->b);

    return vSub;
}

void mostrar_vetor(Vetor *v) {
    printf("(%d, %d)\n", v->a, v->b);
}

int produto_escalar(Vetor *v1, Vetor *v2) {
    return v1->a * v2->a + v1->b * v1->b;
}

void produto_escalar_por_vetor(Vetor *v, int k) {
    v->a *= k;
    v->b *= k;
}