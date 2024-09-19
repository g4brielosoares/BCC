#include <stdio.h>
#include <string.h>
int L, C = 100;

void scanM(char N[][C]) {
    for (int x = 0; x < L; x++) {
        scanf("\n%[^\n]", N[x]);
    }
}

void printM(char N[][C]) {
    for (int x = 0; x < L; x++) {
        printf("Nome %d: %s\n", x + 1, N[x]);
    }
}

void sortS(char N[][C]) {
    int menor, i, j;
    char aux[C];

    for (i = 0; i < L; i++) {
        menor = i;
        for (j = (i + 1); j < L; j++) {
            if (strcmp(N[menor], N[j]) > 0) menor = j;
        }
        strcpy(aux, N[menor]);
        strcpy(N[menor], N[i]);
        strcpy(N[i], aux);
    }
}

int main() {
    scanf("%d", &L);
    char nome[L][C];

        scanM(nome);
        sortS(nome);
        printM(nome);

    return 0;
}