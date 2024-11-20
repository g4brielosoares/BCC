#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    int valor = 0;
    int *aux = NULL;
    Fila *f = NULL;
    f = criarFila();

    while (1) {
        switch (menu(f)) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (enfileirar(f, valor))
                    printf("%d Enfileirado.\n", valor);
                else 
                    printf("Falha ao enfileirar.\n");
                break;
            case 2:
                if (desenfileirar(f))
                    printf("Desenfileirado.\n");
                else 
                    printf("Falha ao desenfileirar.\n");
                break;
            case 3:
                aux = primeiro(f);
                if (aux)
                    printf("Primeiro: %d.\n", *aux);
                else 
                    printf("Lista vazia.\n");
                break;
            case 0:
                return 0;
            default:
                printf("Opcao invalida.\n");
                break;
        }
        getchar();
        getchar();
    }

    destruirFila(&f);

    return 0;
}