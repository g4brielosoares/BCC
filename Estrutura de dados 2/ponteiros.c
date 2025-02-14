#include <stdio.h>

void teste(int x, int *y, int z) {
    *y = 20;
    y++; // pega o proximo endereço - ERRO
    *y = 100;
}

int main() {
    int a = 1, b = 2, c = 3;

    teste(a, &b, c);

    printf("%i %i %i\n", a, b, c);

    return 0;
}