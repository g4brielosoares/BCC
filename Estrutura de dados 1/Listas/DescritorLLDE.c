#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
    struct no *ant;
} No;

typedef struct descritor {
    No *inicio, *fim;
    int qtd;
} Descritor;

int inserirNoInicioDescritorLLDE(Descritor *d, int val) {
    No *novo = (No *) malloc(sizeof(No));
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
    d->qtd++;
    return 1;
}

int inserirOrdenadoDescritorLLDE(Descritor *d, int val) {
    No *novo = malloc(sizeof(No));
    
    if (novo == NULL) return 0;

    novo->valor = val;
    novo->prox = NULL;
    novo->ant = NULL;

    if (d->inicio == NULL) {
        d->inicio = NULL;
        d->fim = NULL;
    } else if (val < d->inicio->valor) {
        novo->prox = d->inicio;
        novo->prox->ant = novo;
        d->inicio = novo;
    } else {
        No *aux = d->inicio;
        while (aux->prox && val > aux->prox->valor)
            aux = aux->prox;

        if (aux->prox == NULL) {
            d->fim->prox = novo;
            novo->ant = d->fim;
            d->fim = novo;
        } else {
            novo->prox = aux->prox;
            novo->ant = aux;
            novo->ant->prox = novo;
            novo->prox->ant = novo;
        }
    }
    return 1;
}

int removerNoInicioDescritorLLDE(Descritor *d) {
    if (d->inicio == NULL)
        return 0;
    
    No *aux = d->inicio;
    if (d->inicio->prox == NULL) {
        d->inicio = NULL;
        d->fim = d->inicio;
    } else {
        d->inicio = d->inicio->prox;
    }
    d->qtd--;
    free(aux);
    return 1;
}

int removerNoFinalDescritorLLDE(Descritor *d) {
    if (d->fim == NULL) return 0;

    No *aux = d->fim;
    if (d->fim->ant == NULL) {
        d->inicio = NULL;
        d->fim = NULL;
    } else {
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
            printf("%d ", aux->valor);
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
    printf("[3] - Inserir Apos Valor.\n");
    printf("[4] - Inserir ordenado.\n");
    printf("[5] - Remover no inicio.\n");
    printf("[6] - Remover no final.\n");
    printf("[7] - Remover valor.\n");
    printf("[8] - Buscar valor.\n");
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
    	       
    	        break;
            case 4:
                printf("Valor: ");
                scanf("%d", &val);
    	        if (inserirOrdenadoDescritorLLDE(&descritorUm, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
                break;
            case 5:
                if (removerNoInicioDescritorLLDE(&descritorUm)) {
                    printf("Valor removido\n");
                } else {
                    printf("Erro ao remover");
                }
                break;
            case 6:
                if (removerNoFinalDescritorLLDE(&descritorUm)) {
                    printf("Valor removido\n");
                } else {
                    printf("Erro ao remover");
                }
                break;
            case 7:
              
                break;
            case 8:
            
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