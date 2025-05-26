#include <stdio.h>
#include <stdlib.h>

const int GRAU = 5;

typedef struct no {
    int quantidadeDeChaves;
    int chaves[5];
    struct no *filho[5 + 1];
} No;

No *criarNo() {
    No *novo = malloc(sizeof(No));
    novo->quantidadeDeChaves = 0;
    for (int i = 0; i < GRAU + 1; i++)
        novo->filho[i] = NULL;

    return novo;
}
void adicionarChave(No **raiz, int valor) {
    int i;
    for (i = (*raiz)->quantidadeDeChaves; i > 0; i--) {
        if (valor > (*raiz)->chaves[i - 1]) break;
        (*raiz)->chaves[i] = (*raiz)->chaves[i - 1];
        (*raiz)->filho[i + 1] = (*raiz)->filho[i];
    }
    (*raiz)->chaves[i] = valor;
    (*raiz)->quantidadeDeChaves++;
}

void copiarMetade(No **raiz, No ** irmao) {
    int i, j;
    for (i = 0, j = (GRAU + 1) / 2; j < GRAU; i++, j++) {
        (*irmao)->chaves[i] = (*raiz)->chaves[j];
        (*raiz)->filho[i] = (*raiz)->filho[j];
        (*irmao)->quantidadeDeChaves++;
        (*raiz)->quantidadeDeChaves--;
    }

    (*raiz)->filho[i] = (*raiz)->filho[j];
    (*raiz)->quantidadeDeChaves--;
}

void obterFilho() {

}

void inserir(No **raiz, int valor) {
    if (*raiz == NULL) {
        *raiz  = criarNo();
        (*raiz)->chaves[0] = valor;
        (*raiz)->quantidadeDeChaves++;
    } else {
        if ((*raiz)->filho[0] == NULL) {
            adicionarChave(raiz, valor);

        } else {
            No *filho = obterFilho(raiz, valor);
            inserir(filho, )
        }
    }
}

void inserirB(No **raiz, int valor) {
    inserir(raiz, valor);
    if ((*raiz)->quantidadeDeChaves == GRAU) {
        printf("dividir a raiz\n");
        No *irmao = criarNo();
        copiarMetade(raiz, &irmao);
        No *novaRaiz = criarNo();
        novaRaiz->chaves[0] = (*raiz)->chaves[(*raiz)->quantidadeDeChaves];
        novaRaiz->quantidadeDeChaves++;
        novaRaiz->filho[0] = *raiz;
        novaRaiz->filho[1] = irmao;
        *raiz = novaRaiz;
    }
}

void preOrdemNivel(No **raiz, int nivel) {
    if (*raiz != NULL) {
        printf("nivel: %i \t", nivel);
        for (int i = 0; i < (*raiz)->quantidadeDeChaves; i++) {
            printf("%i ", (*raiz)->chaves[i]);
        }
        printf("\n");

        for (int j = 0; j < (*raiz)->quantidadeDeChaves; j++) {
            preOrdemNivel(&(*raiz)->filho[j], nivel + 1);
        }
    }
}

void preOrdem(No **raiz) {
    preOrdemNivel(raiz, 0);
}

int main() {
    No *raiz = NULL;
    inserirB(&raiz, 10);
    inserirB(&raiz, 20);
    inserirB(&raiz, 5);

    preOrdem(&raiz);

    return 0;
}