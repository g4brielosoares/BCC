#include <stdio.h>

int main() {
    int x, y, aux, soma = 0;

    scanf("%d %d", &x, &y);
    
    if (y < x) {
        aux = x;
        x = y;
        y = aux;
    }
    
    for (int i = x; i <= y; i++) {
        if (i % 13 != 0) {
            soma += i;
        }
    }

    printf("%d\n", soma);

    return 0;
}