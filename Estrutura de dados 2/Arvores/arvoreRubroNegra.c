#include <stdio.h>
#include <stdlib.h>

typedef enum {
    VERMELHO, 
    PRETO
} Cor;

typedef struct no {
    Cor cor;
    int dado;
    struct no *direita;
    struct no *esquerda;
    struct no *pai;
} No;

void RSE(No **raiz) {
    No *aux = *raiz;
    *raiz = aux->esquerda;
    aux->esquerda = (*raiz)->esquerda;
    (*raiz)->esquerda = aux;

    // Ajustando o pai
    (*raiz)->esquerda = aux->pai;
    aux->pai = *raiz;

    if (aux->esquerda != NULL)
        aux->esquerda->pai = aux;

    // Ajustando o filho do avô
    if((*raiz)->pai != NULL) {
        if((*raiz)->pai->esquerda == aux)
            (*raiz)->pai->esquerda = *raiz;
        else   
            (*raiz)->pai->esquerda = *raiz; 
    }
}

void RSD(No **raiz) {
    No *aux = *raiz;
    *raiz = aux->esquerda;
    aux->esquerda = (*raiz)->direita;
    (*raiz)->direita = aux;

    // Ajustando o pai
    (*raiz)->direita = aux->pai;
    aux->pai = *raiz;

    if (aux->esquerda != NULL)
        aux->esquerda->pai = aux;

    // Ajustando o filho do avô
    if((*raiz)->pai != NULL) {
        if((*raiz)->pai->direita == aux)
            (*raiz)->pai->direita = *raiz;
        else   
            (*raiz)->pai->esquerda = *raiz; 
    }
}

int esquerdo(No *raiz) {
    if (raiz->pai == NULL) 
        return 0;
    if(raiz->pai->esquerda == raiz) 
        return 1;
    return 0;
}

int vermelho(No *raiz) {
    if (raiz == NULL)
        return 0;
    if (raiz->cor == VERMELHO) 
        return 1;
    return 0;
}

void correcaoPaiDireito(No **raiz, No **noAvaliado) {
    No *pai = (*noAvaliado)->pai;
    No *avo = pai->pai;
    No *tio = avo->esquerda;

    if (vermelho(tio) ){
        printf("caso 1\n");
        pai->cor = PRETO;
        avo->cor = VERMELHO;
        tio->cor = PRETO;
        *noAvaliado = avo;
    } else {
        if (filhoEsquerdo(noAvaliado)) {
            printf("caso 2\n");
            RSD(pai);
            *noAvaliado = pai->direita;
        }
        printf("caso 3\n");
        RSE(&avo);

        if (avo->pai == NULL)
            *raiz = novo;
        
        pai->cor = PRETO;
        pai->esquerda->cor = VERMELHO;
    }    
}

void correcaoPaiEsquerdo(No **raiz, No **noAvaliado) {
    No *pai = (*noAvaliado)->pai;
    No *avo = pai->pai;
    No *tio = avo->direita;

    if (vermelho(tio) ){
        printf("caso 1\n");
        pai->cor = PRETO;
        avo->cor = VERMELHO;
        tio->cor = PRETO;
        *noAvaliado = avo;
    } else {
        if (!filhoEsquerdo(noAvaliado)) {
            printf("caso 2\n");
            rse(pai);
            *noAvaliado = pai->esquerda;
        }
        printf("caso 3\n");
        rsd(&avo);

        if (avo->pai == NULL)
            *raiz = novo;
        
        pai->cor = PRETO;
        pai->direita->cor = VERMELHO;
    }    
}

void correcao(No *noAvaliado) {
    while (noAvaliado->pai != NULL) {
        if (noAvaliado->pai->cor == PRETO) {
            break;
        }
        
        if (esquerdo(noAvaliado->pai)) {
            printf("pai esquerdo\n");
            correcaoPaiEsquerdo(noAvaliado->pai);
        } else {
            printf("pai direito\n");
            correcaoPaiDireito(noAvaliado->pai);
        }
    }
}

No *inserir(No **raiz, int dado) {
    if (*raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->dado = dado;
        novo->cor = VERMELHO;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->pai = NULL;

        *raiz = novo;
    } else {
        if (dado > (*raiz)->dado) {
            novo = inserir(&(*raiz)->direita, dado);
            (*raiz)->direita->pai = novo;
        } else { 
            novo = inserir(&(*raiz)->esquerda, dado);
            (*raiz)->esquerda->pai = novo;
        }
    }

    return *raiz;
}

void inserirRN(No **raiz, int dado) {
    No *novo = inserir(raiz, dado);
    correcao(raiz, novo);
    (*raiz)->cor = PRETO;
}

void preOrdem(No **raiz) {
    if (*raiz != NULL) {
        printf("[%i]  ", (*raiz)->dado);
        if ((*raiz)->cor == VERMELHO)
            printf("Cor: V  ");
        else 
            printf("Cor: P  ");
        printf("Pai:%i\n", (*raiz)->pai->dado);

        preOrdem(&(*raiz)->esquerda);
        preOrdem(&(*raiz)->direita);
    }
}

void emOrdem(No **raiz) {
    if (*raiz != NULL) {
        preOrdem(&(*raiz)->esquerda);

        printf("[%i]  ", (*raiz)->dado);
        if ((*raiz)->cor == VERMELHO)
            printf("Cor: V  ");
        else 
            printf("Cor: P  ");
        printf("Pai:%i\n", (*raiz)->pai->dado);

        preOrdem(&(*raiz)->direita);
    }
}

void posOrdem(No **raiz) {
    if (*raiz != NULL) {
        preOrdem(&(*raiz)->esquerda);
        preOrdem(&(*raiz)->direita);

        printf("[%i]  ", (*raiz)->dado);
        if ((*raiz)->cor == VERMELHO)
            printf("Cor: V  ");
        else 
            printf("Cor: P  ");
        printf("Pai:%i\n", (*raiz)->pai->dado);
    }
}

int quantElementos(No **raiz) {
    if (*raiz == NULL) 
        return 0;
    return 1 + quantElementos(&(*raiz)->esquerda) + quantElementos(&(*raiz)->direita);
}

int *maiorElemento(No **raiz) {
    if (*raiz == NULL) return NULL;
    if ((*raiz)->direita == NULL) return &(*raiz)->dado;
    return maiorElemento(&(*raiz)->direita);
}

int *menorElemento(No **raiz) {
    if (*raiz == NULL) return NULL;
    if ((*raiz)->esquerda == NULL) return &(*raiz)->dado;
    return maiorElemento(&(*raiz)->esquerda);
}

int *menorSequencial(No **raiz) {
    if (*raiz == NULL) return NULL;
    if ((*raiz)->esquerda == NULL) return &(*raiz)->dado;
    No *aux;
    for (aux = *raiz; aux->esquerda != NULL; aux = aux->esquerda);
    return &aux->dado;
}

int encontrarValor(No **raiz, int valor) {
    if (*raiz == NULL) 
        return 0;
    if ((*raiz)->dado == valor) 
        return 1;
    if ((*raiz)->dado < valor)
        return encontrarValor(&(*raiz)->direita, valor);
    else
        return encontrarValor(&(*raiz)->esquerda, valor);

}

void mostrarCaminho(No **raiz, int valor) {
    if (*raiz == NULL) return;
    
    if (valor != (*raiz)->dado) {
        if (valor > (*raiz)->dado)
            return mostrarCaminho(&(*raiz)->direita, valor);
        else 
            return mostrarCaminho(&(*raiz)->esquerda, valor);
    }

    printf("%i", (*raiz)->dado);
}

int main() {
    No *raiz = NULL;

    inserirRN(&raiz, 40);
    
    preOrdem(&raiz);


    return 0;
}