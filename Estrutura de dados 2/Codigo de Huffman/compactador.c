#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256

typedef struct noArvore {
    char caractere;
    int frequencia;
    struct noArvore *direita;
    struct noArvore *esquerda;
} NoArvore;

typedef struct noLista {
    struct noArvore *no;
    struct noLista *proximo;
} NoLista;

NoArvore *criarNoArvore(int frequencia, char caractere, NoArvore *direita, NoArvore *esquerda) {
    NoArvore *novo = (NoArvore*)malloc(sizeof(NoArvore));
    if (novo == NULL) return NULL;
    novo->frequencia = frequencia;
    novo->caractere = caractere;
    novo->direita = direita;
    novo->esquerda = esquerda;

    return novo;
}

NoLista *criarNoLista(int frequencia, char caractere, NoArvore *direita, NoArvore *esquerda) {
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    if (novo == NULL) return NULL;
    novo->no = criarNoArvore(frequencia, caractere, direita, esquerda);
    novo->proximo = NULL;

    return novo;
}

void inserirOrdenadoListaRL(NoLista **raiz, int frequencia, char caractere, NoArvore *direita, NoArvore *esquerda) {
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

void inserirOrdenadoLista(NoLista **raiz, int frequencia, char caractere) {
    inserirOrdenadoListaRL(raiz, frequencia, caractere, NULL, NULL);
}

NoArvore *capturarNo(NoLista **raiz) {
    NoLista *aux = *raiz;
    *raiz = (*raiz)->proximo;

    return aux->no;
}

NoArvore *montarArvoreDeHuffman(NoLista **raiz) {
    if (*raiz == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }

    while ((*raiz)->proximo != NULL) {
        NoArvore *direita = capturarNo(raiz), *esquerda = capturarNo(raiz);
        inserirOrdenadoListaRL(raiz, direita->frequencia + esquerda->frequencia, '*', direita, esquerda);
    }

    return (*raiz)->no;
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
    printf("\nLista ordenada: \n");
    for(NoLista *aux = raiz; aux != NULL; aux = aux->proximo)
        printf("%c (%d)\n", (char)aux->no->caractere, aux->no->frequencia);
}

void mostrarTabela(int *tabela) {
    printf("\nTabela de frequencia: \n");
    for (int i = 0; i < TAM; i++)
        if (tabela[i] != 0)
            printf("%c [%d]\n", (char)i, tabela[i]);
}

void preOrdem(NoArvore **raiz, char binario[]) {
    if (*raiz == NULL) return;
    
    if (strcmp( "\0", binario) == 0) printf("raiz");
    printf("%s - %c {%i}\n", binario, (*raiz)->caractere, (*raiz)->frequencia);

    char esquerda[6] = {"\0"}, direita[6] = {"\0"};
    strcpy(esquerda, binario);
    strcpy(direita, binario);

    preOrdem(&(*raiz)->esquerda, strcat(esquerda, "0"));
    preOrdem(&(*raiz)->direita, strcat(direita, "1"));
}

int main() {
    int tabela[TAM] = {0};
    NoLista *raizLista = NULL;

    contarFrequencia(tabela);
    mostrarTabela(tabela);

    for (int i = 0; i < TAM; i++) 
        if (tabela[i] != 0)
            inserirOrdenadoLista(&raizLista, tabela[i], i);
        
    mostrarLista(raizLista);

    NoArvore *raizArvore = montarArvoreDeHuffman(&raizLista);

    if (raizArvore == NULL) {
        printf("Erro: a arvore não foi criada corretamente.\n");
        return 1;
    }

    char binario[6] = {"\0"};
    printf("\nPre-ordem: \n");
    preOrdem(&raizArvore, binario);

    return 0;
}