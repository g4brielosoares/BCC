#include <stdio.h>
#define l 5
#define c 5

void ler(int m[][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimir(int m[][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%2d ", m[i][j]);
        }
    }
}

void somar(int m1[][c], int m2[][c], int m3[][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

int diagonal_principal(int m1[][c]) {
    int soma = 0;
    for(int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j) {
                soma += m1[i][j];
            }
        }
    }
    return soma;
}

int diagonal_secundaria(int m1[][c]) {
    int soma = 0;
    for(int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (i == c - j - 1) {
                soma += m1[i][j];
            }
        }
    }
    return soma;
}

int main() {
    int ma[l][c], mb[l][c], mc[l][c];

    ler(ma);
    printf("MATRIZ A\n");
    imprimir(ma);
    ler(mb);
    printf("MATRIZ B\n");
    imprimir(mb);
    somar(ma, mb, mc);
    imprimir(mc);

    return 0;
}