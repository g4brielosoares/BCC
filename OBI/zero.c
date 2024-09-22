#include <stdio.h>

int main () {
    int N, soma = 0, topo = 0, tam = 0;
    scanf("%d", &N);
    int vetor[N];

    for (tam = 0; tam < N; tam++) {
        scanf("%d", &vetor[topo]);
        if (vetor[topo] == 0) {
            if (topo > 0) topo--;
        } else {
            topo++;
        }
    }

    for (int i = 0; i < topo; i++) 
        soma += vetor[i];

    printf("%d", soma);

    return 0;
}