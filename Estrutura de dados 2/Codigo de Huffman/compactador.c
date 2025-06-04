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

int altura(NoArvore **raiz) {
    if (*raiz == NULL) return -1;

    int esquerda = altura(&(*raiz)->esquerda);
    int direita = altura(&(*raiz)->direita);

    if (esquerda > direita)
        return 1 + esquerda;
    else 
        return 1 + direita;
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
        tabela[(unsigned char)caractere]++;

    fclose(entrada);
}

char **criarDicionario(int altura) {
    char **dicionario = malloc(TAM * sizeof(char *));

    for (int i = 0; i < TAM; i++) 
        dicionario[i] = calloc(altura + 1, sizeof(char));

    return dicionario;
}

void montarDicionario(NoArvore *raiz, char **dicionario, char *memoria, int profundidade) {
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        memoria[profundidade] = '\0';
        strcpy(dicionario[(unsigned char)raiz->caractere], memoria);
        return;
    }

    if (raiz->esquerda != NULL) {
        memoria[profundidade] = '0';
        montarDicionario(raiz->esquerda, dicionario, memoria, profundidade + 1);
    }

    if (raiz->direita != NULL) {
        memoria[profundidade] = '1';
        montarDicionario(raiz->direita, dicionario, memoria, profundidade + 1);
    }
}

void codificar(char **dicionario) {
    FILE *entrada = fopen("../entrada.txt", "r");
    FILE *saida = fopen("../saida.Jsus", "wb");
    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir os arquivos\n");
        exit(1);
    }
    
    long long capacidade = 1024;
    char *buffer = malloc(capacidade * sizeof(char));
    if (!buffer) {
        printf("Erro ao alocar memoria para o buffer\n");
        fclose(entrada);
        fclose(saida);
        exit(1);
    }
    
    int caractere;
    long long totalBits = 0;
    while ((caractere = fgetc(entrada)) != EOF) {
        char *codigo = dicionario[(unsigned char)caractere];

        for (int i = 0; codigo[i] != '\0'; i++) {
            if (totalBits + 1 >= capacidade) {
                capacidade *= 2;
                buffer = realloc(buffer, capacidade * sizeof(char));
                if (!buffer) {
                    printf("Erro ao realocar memoria para o buffer\n");
                    fclose(entrada);
                    fclose(saida);
                    exit(1);
                }
            }

            buffer[totalBits++] = codigo[i];
        }
    }

    int bitsExtra = (8 - (totalBits % 8)) % 8;
    for (int i = 0; i < bitsExtra; i++) {
        if (totalBits + 1 >= capacidade) {
            capacidade *= 2;
            buffer = realloc(buffer, capacidade * sizeof(char));
            if (!buffer) {
                printf("Erro ao realocar memoria para o buffer\n");
                fclose(entrada);
                fclose(saida);
                exit(1);
            }
        }

        buffer[totalBits++] = '0';
    }

    fputc(bitsExtra, saida);

    for (long long i = 0; i < totalBits; i += 8) {
        unsigned char byte = 0;
        for (int j = 0; j < 8; j++) {
            if (buffer[i + j] == '1') {
                byte |= (1 << (7 - j));
            }
        }
        fwrite(&byte, sizeof(unsigned char), 1, saida);
    }

    free(buffer);
    fclose(entrada);
    fclose(saida);
}

void mostrarTabela(int *tabela) {
    printf("\nTabela de frequencia: \n");
    for (int i = 0; i < TAM; i++)
        if (tabela[i] != 0)
            printf("%c [%d]\n", (char)i, tabela[i]);
}

void mostrarLista(NoLista *raiz) {
    printf("\nLista ordenada: \n");
    for(NoLista *aux = raiz; aux != NULL; aux = aux->proximo)
        printf("%c (%d)\n", (char)aux->no->caractere, aux->no->frequencia);
}

void preOrdem(NoArvore **raiz) {
    if (*raiz == NULL) return;
    
    printf("%c {%i}\n", (*raiz)->caractere, (*raiz)->frequencia);
    preOrdem(&(*raiz)->esquerda);
    preOrdem(&(*raiz)->direita);
}

void mostrarDicionario(char **dicionario) {
    for (int i = 0; i < TAM; i++) {
        if (*dicionario[i] != '\0') 
            printf("%c <%s>\n", i, dicionario[i]);
    }
}

int main() {
    NoLista *raizLista = NULL;
    NoArvore *raizArvore = NULL;
    int tabela[TAM] = {0};
    int alturaArvore;
    char **dicionario;
    
    contarFrequencia(tabela);
    mostrarTabela(tabela);

    for (int i = 0; i < TAM; i++) 
        if (tabela[i] != 0)
            inserirOrdenadoLista(&raizLista, tabela[i], i);  

    mostrarLista(raizLista);

    raizArvore = montarArvoreDeHuffman(&raizLista);

    printf("\nPre-ordem: \n");
    preOrdem(&raizArvore);

    alturaArvore = altura(&raizArvore);
    printf("\nAltura: %i\n", alturaArvore);

    char memoria[alturaArvore + 1];
    dicionario = criarDicionario(alturaArvore);

    montarDicionario(raizArvore, dicionario, memoria, 0);

    printf("\nDicionario: \n");
    mostrarDicionario(dicionario);

    codificar(dicionario);

    return 0;
}