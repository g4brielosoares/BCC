#include <stdio.h>

int main() {
    int valor1, valor2, valor3;

    scanf("%d %d %d", &valor1, &valor2, &valor3);

    if (valor1 < valor2 && valor1 < valor3) {
        if (valor2 < valor3) {
            printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", valor1, valor2, valor3, valor1, valor2, valor3);
        } else {
            printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", valor1, valor3, valor2, valor1, valor2, valor3);
        }
    } else if (valor2 < valor3 && valor2 < valor1) {
        if (valor3 < valor1) {
            printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", valor2, valor3, valor1, valor1, valor2, valor3);
        } else {
            printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", valor2, valor1, valor3, valor1, valor2, valor3);
        }
    } else if (valor3 < valor1 && valor3 < valor2) {
        if (valor1 < valor2) {
            printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", valor3, valor1, valor2, valor1, valor2, valor3);
        } else {
            printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", valor3, valor2, valor1, valor1, valor2, valor3);
        }
    }
    
    return 0;
}