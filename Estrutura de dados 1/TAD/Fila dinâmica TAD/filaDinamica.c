#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct node {
    struct node *prox;
    int dado;
} Node;

struct fila {
    Node *inicio;
    Node *fim;
};

Fila *criarFila() {
    Fila *f = malloc(sizeof(Fila));
    if (f == NULL) return NULL;

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

void destruirFila(Fila **f) {
    verificarNulo(*f);
    while (desenfileirar(*f));

    free(*f);
    *f = NULL;
}
 
void verificarNulo(Fila *f) {
    if (f == NULL) {
        printf("Falha no TAD.\n");
        exit(0);
    }
}

int enfileirar(Fila *f, int valor) {
    verificarNulo(f);
    Node *new = malloc(sizeof(Node));
    if (!new) return 0;
    new->prox = NULL;
    new->dado = valor;

    if (f->inicio == NULL) {
        f->inicio = new;
        f->fim = new;
    } else {
        f->fim->prox = new;
        f->fim = new;
    }

    return 1;
}

int desenfileirar(Fila *f) {
    verificarNulo(f);
    if (f->inicio == NULL) return 0;

    Node *temp = f->inicio;
    if (f->inicio->prox == NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    } else 
        f->inicio = f->inicio->prox;

    free(temp);
    return 1;
}

int *primeiro(Fila *f) {
    verificarNulo(f);
    if (f->inicio == NULL) return NULL;

    return &f->inicio->dado;
}

int menu(Fila *f){
    int opc;
    system("clear");
    printf("--> ");
    mostrarFila(*f);
    printf("[0] - Sair.\n");
    printf("[1] - Enfileirar.\n");
    printf("[2] - Desenfileirar.\n");
    printf("[3] - Primeiro elemento.\n\n");
    printf("Escolha uma opção: ");
    scanf("%i", &opc);
    return opc;
}

void mostrarFila(Fila f) {
    verificarNulo(&f);
    if (f.inicio == NULL)
        printf("Lista vazia.");

    for (Node *aux = f.inicio; aux != NULL; aux = aux->prox) 
        printf("%d ", aux->dado);
    printf("\n");
}