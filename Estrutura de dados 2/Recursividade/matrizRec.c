#include <stdio.h>

void mostrarMatriz(int l, int c, int matriz[l][c]) {
    if (l < 0) 
        return;
    
    mostrarMatriz(l, c-1, matriz);
    printf("%i ", matriz[l][c]);
    c = 2;
    l--;
    mostrarMatriz(l, c-1, matriz);
    printf("%i ", matriz[l][c]);

        return;
    

}

int main() {
    int matriz[2][3] = {{1, 2, 3}, {3, 4, 5}};
    int linha = 2, coluna = 3;

    mostrarMatriz(linha-1, coluna-1, matriz);

    return 0;
}