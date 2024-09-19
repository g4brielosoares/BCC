#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct descritor {
    No *inicio, *fim;
} Descritor;

int inserirNoInicioDescritor(Descritor *d, int val) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = val;
    novo->prox = NULL;

    if (val) {
        if (d->inicio == NULL) {
            d->inicio = novo;
            d->fim = novo;
        } else {
            novo->prox = d->inicio;
            d->inicio = novo;
        }
        return 1;
    } else {
        return 0;
    }
}

int inserirNoFinalDescritor(Descritor *d, int val) {
    No *novo = malloc(sizeof(No));
    novo->valor = val;
    novo->prox = NULL;

    if (val) {
        if (d->inicio == NULL) {
            d->inicio = novo;
            d->fim = novo;
        } else {
            d->fim = novo;
        }
        return 1;
    } else {
        return 0;
    }
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

void mostrarLista(Descritor *d) {
    if (d->inicio == NULL) {
        printf("Lista vazia.\n");
    } else {
        for (No *aux = d->inicio; aux; aux = aux->prox) {
            printf("%d ", aux->valor);
        }
        printf("\n");
    }
}

int menu(Descritor *d) {
    int opc;
    system("clear");
    printf("----> ");
	mostrarLista(d);
    printf("[1] - Incluir no inicio.\n");
    printf("[2] - Incluir no indice.\n");
    printf("[0] - Sair.\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    No *listaUm = NULL;
    Descritor *descritorUm;
    int val;

    while (1) {
    	switch (menu(descritorUm)) {
			case 0:
				return 0;
				break;
    	    case 1:
    	        printf("Valor: ");
                scanf("%d", &val);
    	        if (inserirNoInicioDescritor(descritorUm, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
                getchar();
    	        break;
    	    case 2:
                printf("Valor: ");
                scanf("%d", &val);
    	        if (inserirNoFinalDescritor(descritorUm, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
                getchar();
                break;
            case 3:
    	       
    	        break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
               
                break;
            case 7:
              
                break;
            case 8:
            
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