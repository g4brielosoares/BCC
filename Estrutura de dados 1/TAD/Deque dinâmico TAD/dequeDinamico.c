#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

typedef struct no {
    int dado;
    struct no *ant, *prox;
} No;

struct deque {
    No *inicio, *fim;
};

Deque criarDeque() {
    Deque *d = malloc(sizeof(Deque));

    if (d == NULL) {
        printf("Falha ao alocar memoria.\n");
        exit(0);
    }

    d->inicio = NULL;
    d->fim = NULL;

    return d;
}

No *criarNo(int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->dado = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
}

void destruirDeque(Deque **d) {
    verificarNulo(*d);

    while (removerNoInicio(*d));

    free(*d);
    *d == NULL;
}

int inserirNoInicio(Deque *d, int valor) {
    verificarNulo(d);

    No *novo = criarNo(valor);

    if (d->inicio == NULL) {
        d->fim = novo;
        d->inicio = novo;
    } else {
        novo->prox = d->inicio;
        d->inicio->ant = novo;
        d->inicio = novo;
    }

    return 1;
}

int inserirNoFim(Deque *d, int valor) {
    verificarNulo(d);

    No *novo = criarNo(valor);

    if (d->inicio == NULL) {
        d->fim = novo;
        d->inicio = novo;
    } else {
        novo->ant = d->fim;
        d->fim->prox = novo;
        d->fim = novo;
    }

    return 1;
}

int removerNoInicio(Deque *d) {
    verificarNulo(d);

    if (d->inicio == NULL) return 0;

    No *aux = d->inicio;
    d->inicio = d->inicio->prox;

    if (d->inicio == NULL)
        d->fim = NULL;
    else
        d->inicio->ant = NULL;

    free(aux);
}

int removerNoFim(Deque *d) {
    verificarNulo(d);

    if (d->inicio == NULL) return 0;

    No *aux = d->fim;
    d->fim = d->fim->ant;
    
    if (d->fim == NULL) 
        d->inicio = NULL;
    else
        d->fim->prox = NULL;

    free(aux);
}

int *consultarInicio(Deque *d) {
    verificarNulo(d);

    if (d->inicio == NULL) return NULL;

    return &d->inicio->dado;
}

int *consultarFim(Deque *d) {
    verificarNulo(d);

    if (d->fim == NULL) return NULL;

    return &d->fim->dado;
}

void mostrarDeque(Deque *d) {
    verificarNulo(d);

    if (d->inicio == NULL)b
        printf("Lista vazia.");

    for (No *aux = d->inicio; aux != NULL; aux = aux->prox) 
        printf("%d ", aux->dado);
    printf("\n");
}

void verificarNulo(Deque *d) {
    if (d == NULL) {
        printf("Falha no TAD.\n");
        exit(0);
    }
}