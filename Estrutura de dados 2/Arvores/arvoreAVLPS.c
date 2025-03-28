#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *direita, *esquerda;
    int dado;
} No;

No *inserir(No *raiz, int dado) {
    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->dado = dado;
        novo->esquerda = NULL;
        novo->direita = NULL;
        raiz = novo;

    } else {
        if (dado > raiz->dado) 
            raiz->direita = inserir(raiz->direita, dado);
        else
            raiz->esquerda = inserir(raiz->esquerda, dado);
    }

    return raiz;
}

void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%i ", raiz->dado);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

No *removerMaior(No *raiz) {
    if (raiz == NULL) 
        return NULL;
    if (raiz->direita == NULL) {
        No *aux = raiz->direita;
        raiz = raiz->esquerda;
        free(aux);

        return raiz;
    }

    raiz->direita = removerMaior(raiz->direita);
    return raiz;
}

No *maiorElemento(No *raiz) {
    No *aux = raiz;
    while (aux->direita) {
        aux = aux->direita;
    }
    return aux;
}

No *removerPorValor(No *raiz, int valor) {
    if (raiz == NULL) 
        return NULL;

    if (raiz->dado == valor) {
        No *aux = raiz;
        if (raiz->direita == NULL) {
            raiz = raiz->direita;
        } else if (raiz->esquerda == NULL) {
            raiz = raiz->esquerda;
        } else {
            raiz->dado = maiorElemento(raiz->esquerda);
            raiz->esquerda = removerPorValor(raiz->esquerda, raiz->dado);
        }

        free(aux);
    } else {
        if (raiz->dado < valor) {
            raiz->esquerda = removerMaior(raiz->esquerda);
        } else {   
            raiz->direita = removerMaior(raiz->direita);
        }
    }

    return raiz;
}

int main() {
    No *raiz = NULL;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 40);
    raiz = removerMaior(raiz);

    preOrdem(raiz);
}