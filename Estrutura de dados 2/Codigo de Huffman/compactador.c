#include <stdio.h>
#include <stdlib.h>

#define TAM 256

typedef struct noArvore {
    char caractere;
    int frequencia;
    struct noLista *direita;
    struct noLista *esquerda;
} NoArvore;

typedef struct noLista {
    struct noArvore *no;
    struct noLista *proximo;
} NoLista;

NoArvore *criarNoArvore(int frequencia, char caractere, NoLista *direita, NoLista *esquerda) {
    NoArvore *novo = (NoArvore*)malloc(sizeof(NoArvore));
    if (novo == NULL) return NULL;
    novo->frequencia = frequencia;
    novo->caractere = caractere;
    novo->direita = direita;
    novo->esquerda = esquerda;

    return novo;
}

NoLista *criarNoLista(int frequencia, char caractere, NoLista *direita, NoLista *esquerda) {
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    if (novo == NULL) return NULL;
    novo->no = criarNoArvore(frequencia, caractere, direita, esquerda);
    novo->proximo = NULL;

    return novo;
}

void inserirOrdenadoLista(NoLista **raiz, int frequencia, char caractere, NoLista *direita, NoLista *esquerda) {
    NoLista *novo = criarNoLista(frequencia, caractere, direita, esquerda);

    if (*raiz == NULL || (*raiz)->no->frequencia > frequencia) {
        novo->proximo = *raiz;
        *raiz = novo;
        return;
    }

    NoLista *aux = *raiz;
    while (aux->proximo != NULL && aux->proximo->no->frequencia <= frequencia)
        aux = aux->proximo;

    novo->proximo = aux->proximo;
    aux->proximo = novo;
}

void inserirOrdenadoListaNULL(NoLista **raiz, int frequencia, char caractere) {
    inserirOrdenadoLista(raiz, frequencia, caractere, NULL, NULL);
}

NoLista *capturarNo(NoLista **raiz) {
    NoLista *aux = *raiz;
    *raiz = (*raiz)->proximo;

    return aux;
}

void montarArvoreDeHuffman(NoLista **raiz) {
    if (*raiz == NULL) return;

    while ((*raiz)->proximo != NULL) {
       inserirOrdenadoLista(raiz, (*raiz)->no->frequencia, '$', capturarNo(raiz), capturarNo(&(*raiz)->proximo));
    }
}

void contarFrequencia(int *tabela) {
    FILE *entrada = fopen("../entrada.txt", "r");

    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(0);
    }

    int caractere;
    while ((caractere = fgetc(entrada)) != EOF)
        tabela[caractere]++;

    fclose(entrada);
}

void mostrarLista(NoLista *raiz) {
    printf("Lista ordenada: \n");
    for(NoLista *aux = raiz; aux != NULL; aux = aux->proximo)
        printf("%c (%d)\n", (char)aux->no->caractere, aux->no->frequencia);
}

void mostrarTabela(int *tabela) {
    printf("Tabela de frequencia: \n");
    for (int i = 0; i < TAM; i++)
        if (tabela[i] != 0)
            printf("%c [%d]\n", (char)i, tabela[i]);
}

int main() {
    int tabela[TAM] = {0};
    NoLista *raiz = NULL;

    contarFrequencia(tabela);

    for (int i = 0; i < TAM; i++) 
        if (tabela[i] != 0)
            inserirOrdenadoListaNULL(&raiz, tabela[i], i);

    montarArvoreDeHuffman(&raiz);
    
    mostrarLista(raiz);

    return 0;
}