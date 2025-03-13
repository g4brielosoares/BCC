#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esquerda; // menor
    struct no *direita;  // maior
} No;

void criarNo(No **raiz, int dado) {
    if (*raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->dado = dado;
        novo->esquerda = NULL;
        novo->direita = NULL;
        *raiz = novo;
    } else {
        if (dado > (*raiz)->dado) 
            criarNo(&(*raiz)->direita, dado);
        else
            criarNo(&(*raiz)->esquerda, dado);
    }
}

void preOrdem(No **raiz) {
    if (*raiz != NULL) {
        printf("%i ", (*raiz)->dado);
        preOrdem(&(*raiz)->esquerda);
        preOrdem(&(*raiz)->direita);
    }
}

void emOrdem(No **raiz) {
    if (*raiz != NULL) {
        preOrdem(&(*raiz)->esquerda);
        printf("%i ", (*raiz)->dado);
        preOrdem(&(*raiz)->direita);
    }
}

void posOrdem(No **raiz) {
    if (*raiz != NULL) {
        preOrdem(&(*raiz)->esquerda);
        preOrdem(&(*raiz)->direita);
        printf("%i ", (*raiz)->dado);
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

int removerMaiorSequencial(No **raiz) {
    if (*raiz == NULL) return 0;

    No *aux, *ant;
    for (aux = *raiz; aux->direita != NULL; aux = aux->direita) {
        ant = aux;
    }

    if (ant == NULL) {
        *raiz = (*raiz)->esquerda;
    } else {
        ant->direita = aux->esquerda;
    }
    
    free(aux);

    return 1;
}

int removerMaior(No **raiz) {
    if (*raiz == NULL) 
        return 0;

    if ((*raiz)->direita == NULL) {
        No *aux = *raiz;
        *raiz = aux->esquerda; // pode ser um no ou pode ser nulo!

        free(aux);

        return 0;
    }

    return removerMaior(&(*raiz)->direita);
}

int removerPorValor(No **raiz, int valor) {
    if (*raiz == NULL)
        return 0;

    if ((*raiz)->dado == valor) {
        if ((*raiz)->esquerda == NULL) { // Caso 1
            No *aux = *raiz;
            *raiz = (*raiz)->direita;
            
            free(aux);
            return 1;
        }
        if ((*raiz)->direita == NULL) { // Caso 2
            No *aux = *raiz;
            *raiz = (*raiz)->esquerda;
            
            free(aux);
            return 1;
        }

        (*raiz)->dado = *maiorElemento(&(*raiz)->esquerda); // Caso 3
        return removerPorValor(&(*raiz)->esquerda, valor);
    
    } else {
        if (valor > (*raiz)->dado) {
            return removerPorValor(&(*raiz)->direita, valor);
        } else {
            return removerPorValor(&(*raiz)->esquerda, valor);
        }
    }
}

void mostrarFolhas(No **raiz) {
    if (*raiz == NULL) 
        return;
    if ((*raiz)->esquerda == NULL && (*raiz)->direita == NULL) 
        printf("%i ", (*raiz)->dado);

    mostrarFolhas(&(*raiz)->esquerda);
    mostrarFolhas(&(*raiz)->direita);
}

int altura(No **raiz) {
    if (*raiz == NULL) return -1;

    int esquerda = altura(&(*raiz)->esquerda);
    int direita = altura(&(*raiz)->direita);

    if (esquerda > direita)
        return 1 + esquerda;
    else 
        return 1 + direita;
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

void RSE(No **raiz) {
    if (*raiz == NULL || (*raiz)->direita == NULL) {
        printf("Impossivel rotacionar.\n");
        exit(0);
    }
    
    No *aux = *raiz;
    *raiz = aux->direita;
    aux->direita = (*raiz)->esquerda;
    (*raiz)->esquerda = aux;
}

void RSD(No **raiz) {
    if (*raiz == NULL || (*raiz)->esquerda == NULL) {
        printf("Impossivel rotacionar.\n");
        exit(0);
    }

    No *aux = *raiz;
    *raiz = aux->esquerda;
    aux->esquerda = (*raiz)->direita;
    (*raiz)->direita = aux;
}

void RDD(No **raiz) {
    RSE(&(*raiz)->esquerda);
    RSD(raiz);
}

void RDE(No **raiz) {
    RSD(&(*raiz)->direita);
    RSE(raiz);
}

int menu(No **raiz) {
    int opc;
    system("cls");
    printf("Quantidade de elementos: %i\n", quantElementos(raiz));
    printf("Altura: %i\n", altura(raiz));
    printf("Pre ordem: ");
    preOrdem(raiz);
    printf("\nEm ordem: ");
    emOrdem(raiz);
    printf("\nPos ordem: ");
    posOrdem(raiz);
    printf("\nFolhas: ");
    mostrarFolhas(raiz);
    printf("\n\n");
    printf("[1] - Inserir elemento.\n");
    printf("[2] - Maior elemento.\n");
    printf("[3] - Menor elemento.\n");
    printf("[4] - Remover maior.\n");
    printf("[5] - Remover por valor.\n");
    printf("[6] - Mostrar caminho do no ate a raiz.\n");
    printf("Escolha uma opcao: ");

    scanf("%i", &opc);
    return opc;
}

int main() {
    No *raiz = NULL;
    int dado, *aux;
/*
    while (1) {
        switch (menu(&raiz)) {
            case 0:
                return 0;
            case 1:
                scanf("%i", &dado);
                criarNo(&raiz, dado);

                break;
            case 2:
                aux = maiorElemento(&raiz);
                printf("Maior valor: %i\n", *aux);

                break;
            case 3:
                aux = menorSequencial(&raiz);
                printf("Menor valor: %i\n", *aux);

                break;
            case 4:
                removerMaior(&raiz);
                printf("Maior valor removido.\n");

                break;
            case 5:
                printf("Qual valor deseja remover? ");
                scanf("%i", &dado);

                if (removerPorValor(&raiz, dado) == 0) 
                    printf("%i nao encontrado.\n", dado);
                else
                    printf("%i removido.\n", dado);

                break;
            case 6:
                printf("Qual valor deseja ver? ");
                scanf("%i", &dado);

                if (encontrarValor(&raiz, dado) == 0) 
                    printf("%i nao encontrado.\n", dado);
                else 
                    mostrarCaminho(&raiz, dado);
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
        }
        getchar();
        getchar();
    }
*/

    criarNo(&raiz, 7);
    criarNo(&raiz, 5);
    criarNo(&raiz, 3);
    preOrdem(&raiz);
    RSD(&(raiz)->direita);
    preOrdem(&raiz);
    return 0;
}