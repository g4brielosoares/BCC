#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prox;
    int dado;
} Node;

typedef struct descritor {
    Node *inicio;
    Node *fim;
} Descritor;

int queue(Descritor *D, int valor) {
    Node *new = malloc(sizeof(Node));
    if (!new) return 0;
    new->prox = NULL;
    new->dado = valor;

    if (D->inicio == NULL) {
        D->inicio = new;
        D->fim = new;
    } else {
        D->fim->prox = new;
        D->fim = new;
    }

    return 1;
}

int dequeue(Descritor *D) {
    if (D->inicio == NULL) return 0;

    Node *temp = D->inicio;
    if (D->inicio->prox == NULL) {
        D->inicio = NULL;
        D->fim = NULL;
    } else 
        D->inicio = D->inicio->prox;

    free(temp);
    return 1;
}

int *primeiro(Descritor *D) {
    if (D->inicio == NULL) return NULL;

    return &D->inicio->dado;
}

void mostrarFila(Descritor D) {
    if (D.inicio == NULL)
        printf("Lista vazia.");

    for (Node *aux = D.inicio; aux != NULL; aux = aux->prox) 
        printf("%d ", aux->dado);
    printf("\n");
}

int main() {
    Descritor D;
    D.inicio = NULL;
    D.fim = NULL;

    while (1) {
        switch (menu(D)) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                break:
            default:
                break;
        }
        getchar();
        getchar();
    }

    return 0;
}