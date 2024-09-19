#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void inserirNoInicio(No **lista, int val) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = val;
    novo->prox = *lista;
    *lista = novo;
}

void inserirNoFinal(No **lista, int val) {
    No *novo = malloc(sizeof(No));
    novo->valor = val;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *aux = *lista;
        
        while (aux->prox) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }
}

void inserirNoIndice(No **lista, int val, int indice) {
    if (indice == 0) {
        inserirNoInicio(lista, val);
        return;
    }

    No *novo = malloc(sizeof(No));
    No *atual = *lista, *anterior = NULL;
    int i = 0;
    novo->valor = val;
    novo->prox = NULL;

    for (i = 0; atual && i < indice; i++) {
        anterior = atual;
        atual = atual->prox;
    }

    if (i != indice || anterior == NULL) {
        free(novo);
        return;
    }

    anterior->prox = novo;
    novo->prox = atual;
}

void removerNoInicio(No **lista) {
    if (*lista == NULL) {
        return;
    } else {
        No *aux = *lista;

        *lista = (*lista)->prox;
        free(aux);
        return;
    }
}

void removerNoFinal(No **lista) {
    No *aux = *lista;

    if (*lista == NULL) {
        return;
    } else if ((*lista)->prox == NULL) {
        free(*lista);
        *lista = NULL;
        return;
    } else {
        for (aux = *lista; aux->prox->prox; aux = aux->prox);

        free(aux->prox);
        aux->prox = NULL;
        return;
    }
}


void removerNoIndice(No **lista, int indice) {
    if (indice == 0) {
        removerNoInicio(lista);
        return;
    }

    No *atual = *lista, *anterior = NULL;

    for (int i = 0; atual && i < indice; i++) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return;

    anterior->prox = atual->prox;
    free(atual);
    return;
}

No* removerValor(No **lista, int val) {
    No *aux, *remover = NULL;

    if (*lista) {
        if ((*lista)->valor == val) {
            remover = *lista;
            *lista = remover->prox;
        } else {
            for (aux = *lista; aux && aux->prox->valor != val; aux = aux->prox);
            if (aux) {
                remover = aux->prox;
                aux->prox = remover->prox;
            }
        }
    }
    return remover;
}

float media(No **lista) {
    int soma = 0, total = 0;

    if (lista == NULL) {
        return 0;
    } else {
        for (No *aux = *lista; aux; aux = aux->prox) {
            soma = soma + aux->valor;
            total++;
        }
    }
    return (float)soma / total;
}

void mostrarLista(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
    } else {
        for (No *aux = lista; aux; aux = aux->prox) {
            printf("%d ", aux->valor);
        }
        printf("\n");
    }
}

int menu(No *lista) {
    int opc;
    system("clear");
    printf("----> ");
	mostrarLista(lista);
    printf("[1] - Incluir no inicio.\n");
    printf("[2] - Incluir no indice.\n");
    printf("[3] - Incluir no final.\n");
    printf("[4] - Remover no inicio.\n");
    printf("[5] - Remover valor.\n");
    printf("[6] - Remover no indice.\n");
    printf("[7] - Remover no final.\n");
    printf("[8] - Media da lista.\n");
    printf("[0] - Sair.\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    No *listaUm = NULL, *remover;
    int val, indice;

    while (1) {
    	switch (menu(listaUm)) {
			case 0:
				return 0;
				break;
    	    case 1:
    	        printf("valor: ");
    	        scanf("%d", &val);
    	        inserirNoInicio(&listaUm, val);
    	        break;
    	    case 2:
                printf("valor: ");
    	        scanf("%d", &val);
                printf("Posicao: ");
    	        scanf("%d", &indice);
                inserirNoIndice(&listaUm, val, indice);
                break;
            case 3:
    	        printf("valor: ");
    	        scanf("%d", &val);
    	        inserirNoFinal(&listaUm, val);
    	        break;
            case 4:
                removerNoInicio(&listaUm);
                break;
            case 5:
                printf("valor: ");
    	        scanf("%d", &val);
                remover = removerValor(&listaUm, val);
                if (remover) {
                    printf("\nO valor %d foi removido.\n", remover->valor);
                    getchar();
                    free(remover);
                }
                break;
            case 6:
                printf("Indice: ");
    	        scanf("%d", &indice);
                removerNoIndice(&listaUm, indice);
                break;
            case 7:
                removerNoFinal(&listaUm);
                break;
            case 8:
            if (media(&listaUm)) {
                printf("\nA media de todos os valores da lista e: %.1f", media(&listaUm));
            } else {
                printf("Lista vazia.\n");
            }
            getchar();
                break;
            case 9:

                break;
            default:
                printf("\nOpcao invalida.\n");
                break;
    	}
    	getchar();
	}

    return 0;
}