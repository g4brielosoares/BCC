#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct descritor {
    No *inicio, *fim;
    int qtd;
} Descritor;

int inserirNoInicioDescritorLLSE(Descritor *d, int val) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return 0;
    
    novo->valor = val;
    novo->prox = NULL;

    if (d->inicio == NULL) {
        d->inicio = novo;
        d->fim = novo;
    } else {
        novo->prox = d->inicio;
        d->inicio = novo;
    }
    d->qtd++;
    return 1;
}

int inserirNoFinalDescritorLLSE(Descritor *d, int val) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->valor = val;
    novo->prox = NULL;

    if (d->inicio == NULL) {
        d->inicio = novo;
        d->fim = novo;
    } else {
        d->fim->prox = novo;
        d->fim = novo;
    }
    d->qtd++;
    return 1;
}

int removerNoInicioDescritorLLSE() {
    
}

void mostrarListaDescritorLLSE(Descritor *d) {
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
	mostrarListaDescritorLLSE(&d);
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
    	        if (inserirNoInicioDescritorLLSE(&descritorUm, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
    	        break;
    	    case 2:
                printf("Valor: ");
                scanf("%d", &val);
    	        if (inserirNoFinalDescritorLLSE(&descritorUm, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
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
            default:
                printf("\nOpcao invalida.\n");
                break;
    	}
        getchar();
    	getchar();
	}

    return 0;
}