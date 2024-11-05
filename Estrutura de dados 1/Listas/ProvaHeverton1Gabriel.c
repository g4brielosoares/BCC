#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
    struct no *ant;
} No;

typedef struct descritor {
    No *inicio, *fim, *maior;
    int qtd;
} Descritor;

int inserirNoInicioDescritorLLDE(Descritor *d, int val) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->valor = val;
    novo->prox = NULL;
    novo->ant = NULL;

    if (d->inicio == NULL) {
        d->inicio = novo;
        d->fim = novo;
    } else {
        novo->prox = d->inicio;
        novo->prox->ant = novo;
        d->inicio = novo;
    }

    if (d->maior == NULL || d->maior->valor < novo->valor) {
        d->maior = novo;
    }

    d->qtd++;
    return 1;
}

int inserirNoFinalDescritorLLDE(Descritor *d, int val) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->valor = val;
    novo->prox = NULL;
    novo->ant = NULL;
    
    if (d->inicio == NULL) {
        d->inicio = novo;
        d->fim = novo;
    } else {
        d->fim->prox = novo;
        novo->ant = d->fim;
        d->fim = novo;
    }

    if (d->maior == NULL || d->maior->valor < novo->valor) {
        d->maior = novo;
    }

    d->qtd++;
    return 1;
}

int removerNoFinalDescritorLLDE(Descritor *d) {
    if (d->fim == NULL) return 0;

    No *aux = d->fim;
    if (d->fim->ant == NULL) {
        d->inicio = NULL;
        d->fim = NULL;
    } else {
        if (d->maior == d->fim) {
            No *temp = d->inicio;
            int dif = d->maior->valor;
            d->maior = d->inicio;
            while (temp) {
                if (temp->valor > d->maior->valor && temp->valor != dif)
                    d->maior = temp;
                
                temp = temp->prox;
            }
        }

        d->fim = d->fim->ant;
        d->fim->prox = NULL;
    }
    d->qtd--;
    free(aux);
    return 1;
}

void mostrarListaDescritorLLDE(Descritor *d) {
    if (d->inicio == NULL) {
        printf("Lista vazia.\n");
    } else {
        for (No *aux = d->inicio; aux; aux = aux->prox) {
            if (aux == d->maior) {
                printf("[%d] ", aux->valor);
            } else {
                printf("%d ", aux->valor);
            }
        }
        printf("\n");
    }
}

int menu(Descritor d) {
    int opc;
    system("clear");
    printf("----> ");
	mostrarListaDescritorLLDE(&d);
    printf("[1] - Inserir no inicio.\n");
    printf("[2] - Inserir no final.\n");
    printf("[3] - Remover no final.\n");
    printf("[0] - Sair.\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    Descritor descritorUm;
    int val;

    descritorUm.inicio = NULL;
    descritorUm.fim = NULL;
    descritorUm.qtd = 0;
    descritorUm.maior = NULL;

    while (1) {
    	switch (menu(descritorUm)) {
			case 0:
				return 0;
				break;
    	    case 1:
    	        printf("Valor: ");
                scanf("%d", &val);
    	        if (inserirNoInicioDescritorLLDE(&descritorUm, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
    	        break;
    	    case 2:
    	        printf("Valor: ");
                scanf("%d", &val);
    	        if (inserirNoFinalDescritorLLDE(&descritorUm, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
                break;
            case 3:
    	        if (removerNoFinalDescritorLLDE(&descritorUm)) {
                    printf("Valor Removido.\n");
                } else {
                    printf("Falha ao remover.\n");
                }
    	        break;
            default:
                printf("\nOpcao invalida.\n");
                break;
    	}
        getchar();
    	getchar();
	}

    return 0;
}