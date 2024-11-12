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
    Pilha *pilha;
    pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->cabeca = NULL;
    return pilha;
}

void destruir_pilha(Pilha **p){
    if (*p == NULL){
        printf("Erro ao usar o TAD.\n");
        exit(0);
    }
    
    while(desempilhar(p->cabeca));
    free(*p);
    *p=NULL;    
}

int empilhar(Pilha *p, int vlr){
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
    if (p->cabeca == NULL)
        return 0;
    No *aux;
    aux = p->cabeca;
    p->cabeca = aux->prox;
    free(aux);
    return 1;
}

int *topo(Pilha *p){
    if (p->cabeca == NULL)
        return NULL;
    return &p->cabeca->dado;
}

int testar_pilha(Pilha *p){
    if (p->cabeca == NULL) {
        printf("Erro no TAD.\n");
        exit(0);
    }
    else 1
}

void mostrar_pilha(Pilha *p){

}
