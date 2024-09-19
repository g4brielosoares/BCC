#include <stdio.h>

void impar_par(int num) {
    int resultado;
    
    resultado = num % 2;
    
    if (resultado == 0) {
        printf("par");
    } else {
        printf("impar");
    }
}

int main() {
    int numero;

    scanf("%d", &numero);
    impar_par(numero);

    return 0;
}