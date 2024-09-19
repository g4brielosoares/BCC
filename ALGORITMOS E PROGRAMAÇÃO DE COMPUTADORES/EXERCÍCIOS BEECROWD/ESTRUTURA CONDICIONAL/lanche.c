#include <stdio.h>

int main() {
    float codigo, quantidade, resultado = 0;
    scanf("%f %f", &codigo, &quantidade);
    if (codigo == 1) {
        codigo = 4.00;
    } else if (codigo == 2) {
        codigo = 4.50;
    } else if (codigo == 3) {
        codigo = 5.00;
    } else if (codigo == 4) {
        codigo = 2.00;
    } else if (codigo == 5) {
        codigo = 1.50;
    } 
    resultado = codigo * quantidade;
    printf("Total: R$ %.2f\n", resultado);
    return 0;
}
