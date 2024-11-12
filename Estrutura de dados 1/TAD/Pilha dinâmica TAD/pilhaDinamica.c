#include "pilha.h"
#include <stdio.h>

typedef struct no {
    int dado;
    struct no *prox;
}No;

struct pilha{
   No *cabeca;
};

Pilha *criar_pilha(){
    testar_pilha_nula(p);

    Pilha *pilha;
    pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->cabeca = NULL;
    return pilha;
}

void destruir_pilha(Pilha **p){
    testar_pilha_nula(p);

    if (*p == NULL){
        printf("Erro ao usar o TAD.\n");
        exit(0);
    }
    
    while(desempilhar(*p));
    free(*p);
    *p=NULL;    
}

int empilhar(Pilha *p, int vlr){
    testar_pilha_nula(p);

    No *novo;
    novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;
    novo->dado = vlr;
    novo->prox = NULL;
    
    if (p->cabeca == NULL)
        p->cabeca = novo;
    else{
        novo->prox = p->cabeca;
        p->cabeca = novo;
    }
    return 1;
}

int desempilhar(Pilha *p){
    testar_pilha_nula(p);

    if (p->cabeca == NULL)
        return 0;
    No *aux;
    aux = p->cabeca;
    p->cabeca = aux->prox;
    free(aux);
    return 1;
}

int *topo(Pilha *p){
    testar_pilha_nula(p);

    if (p->cabeca == NULL)
        return NULL;
    return &p->cabeca->dado;
}

void testar_pilha_nula(Pilha *p){
    if (p == NULL) {
        printf("Erro no TAD.\n");
        exit(0);
    }
}

void mostrar_pilha(Pilha *p){
    testar_pilha_nula(p);
    
    for (Pilha aux = p; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->dado);
    }
}
