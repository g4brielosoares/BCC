#include <stdio.h>
#define TAM 10

int main() {
    int N[TAM];

    scanf("%d", &N[0]);

    for (int i = 0; i < TAM; i++) {
        printf("N[%d] = %d\n", i, N[i]);
        N[i + 1] = N[i] * 2;
    }    

    return 0;
}