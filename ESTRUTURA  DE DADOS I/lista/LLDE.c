#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
    struct no *ant;
} No;

int busca(No **lista, int val) {
    No *aux = *lista;
    while (aux) {
        if (aux->valor == val) return 1;
        aux = aux->prox;
    }
    return 0;
}

int inserirNoInicio(No **lista, int val) {
    No *novo = malloc(sizeof(No));
    novo->valor = val;
    novo->prox = NULL;
    novo->ant = NULL;
    
    if (novo) {
        if (*lista == NULL) {
            *lista = novo;
        } else {
            (*lista)->ant = novo;
            novo->prox = *lista;
            *lista = novo;
        }
        return 1;
    } else {
        return 0;
    }
}

int inserirNoFinal(No **lista, int val) {
    No *novo = malloc(sizeof(No)), *aux = *lista;
    novo->valor = val;
    novo->prox = NULL;
    novo->ant = NULL;

    if (novo) {
        if (*lista == NULL) {
            *lista = novo;
        } else {
            while (aux->prox != NULL)
                aux = aux->prox;

            aux->prox = novo;
            novo->ant = aux;
        }
        return 1;
    } else {
        return 0;
    }    
}

int inserirOrdenado(No **lista, int val) {
    No *novo = malloc(sizeof(No));
    novo->valor = val;
    novo->prox = NULL;
    novo->ant = NULL;

    if (novo) {
        if (*lista == NULL) {
            *lista = novo;
        } else {
            No *q, *p = *lista;
            q = NULL;
            while (p) {
                if (p->valor > val)
                    break;
                q = p;
                p = p->prox;
            }

            if (q == NULL) {
                novo->prox = *lista;
                p->ant = novo;
                *lista = novo;
            } else if (p == NULL) {
                q->prox = novo;
                novo->ant = q;
            } else {
                novo->prox = p;
                novo->ant = q;
                q->prox = novo;
                p->ant = novo;
            }
        }
        return 1;
    } else {
        return 0;
    }    
}

int inserirAposValor(No **lista, int val, int valAnt) {
    if (busca(lista, valAnt) == 0) return 0;

    No *novo = malloc(sizeof(No));
    novo->valor = val;
    novo->prox = NULL;
    novo->ant = NULL;

    if (novo) {
        if (*lista == NULL) {
            *lista = novo;
        } else {
            No *aux = *lista;
            
            while (aux->valor != valAnt && aux->prox) 
                aux = aux->prox;

            if (aux->prox == NULL) {
                aux->prox = novo;
                novo->ant = aux;
            } else {
                novo->prox = aux->prox;
                aux->prox->ant = novo;
                novo->ant = aux;
                aux->prox = novo;
            }
        }
        return 1;
    } else {
        return 0;
    }    
}

int removerNoInicio(No **lista) {
    if (*lista) {
        if ((*lista)->prox == NULL) {
            *lista = NULL;
            free(*lista);
        } else { 
            No *aux = *lista;
            *lista = (*lista)->prox;
            (*lista)->ant = NULL;
            free(aux);
        }
        return 1;
    } else 
        return 0;
}

int removerNoFinal(No **lista) {
    if (*lista == NULL) {
        return 0;
    } else if ((*lista)->prox == NULL) {
        free(*lista);
        *lista = NULL;
    } else {
        No *aux = *lista;

        while (aux->prox) 
            aux = aux->prox;

        aux->ant->prox = NULL;
        free(aux);
    }
    return 1;
}

int removerValor(No **lista, int val) {
    if (busca(lista, val) == 0) return 0;

    if (*lista == NULL) {
        return 0;
    } else if ((*lista)->prox == NULL) {
        free(*lista);
        *lista = NULL;
    } else {
        No *aux = *lista;

        while (aux->prox && aux->valor != val) 
            aux = aux->prox;

        if (aux->prox == NULL) {
            aux->ant->prox = NULL;
        } else if (aux->ant == NULL) {
            *lista = (*lista)->prox;
            (*lista)->ant = NULL;
        } else if (aux->valor == val) {
            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
        } 
        free(aux);  
    }
    return 1;
}

int verificarIntegridade(No **lista) {
    if (*lista == NULL) return 0;

    No *aux = *lista;
    int count = 0;

    while (aux->prox) {
        aux = aux->prox;
        count++;
    }

    while (aux->ant) {
        aux = aux->ant;
        count--;
    }

    return (count == 0);  
}

void mostrarLista(No *lista) {
    No *aux = lista;
    if (lista) {
        while (aux) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    } else {
        printf("Lista vazia.\n");
    }
}

int menu(No *lista) {
    int opc;
    system("clear");
    printf("----> ");
	mostrarLista(lista);
    printf("[1] - Inserir no inicio.\n");
    printf("[2] - Inserir no final.\n");
    printf("[3] - Inserir Apos Valor.\n");
    printf("[4] - Inserir ordenado.\n");
    printf("[5] - Remover no inicio.\n");
    printf("[6] - Remover no final.\n");
    printf("[7] - Remover valor.\n");
    printf("[8] - Buscar valor.\n");
    printf("[9] - Verificar integridade.\n");
    printf("[0] - Sair.\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    No *listaDois = NULL;
    int val, valAnt;

    while (1) {
    	switch (menu(listaDois)) {
			case 0:
				return 0;
				break;
    	    case 1:
                printf("Valor: ");
                scanf("%d", &val);
    	        if (inserirNoInicio(&listaDois, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
    	        break;
    	    case 2:
                printf("Valor: ");
                scanf("%d", &val);
                if (inserirNoFinal(&listaDois, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
                break;
            case 3:
                printf("Valor: ");
                scanf("%d", &val);
                printf("Apos: ");
                scanf("%d", &valAnt);
                if (inserirAposValor(&listaDois, val, valAnt)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
                break;
            case 4:
    	        printf("Valor: ");
                scanf("%d", &val);
                if (inserirOrdenado(&listaDois, val)) {
                    printf("Valor inserido.\n");
                } else {
                    printf("Falha ao inserir.\n");
                }
    	        break;
            case 5:
                if (removerNoInicio(&listaDois)) {
                    printf("Valor removido.\n");
                } else {
                    printf("Falha ao remover.\n");
                }
                break;
            case 6:
                if (removerNoFinal(&listaDois)) {
                    printf("Valor removido.\n");
                } else {
                    printf("Falha ao remover.\n");
                }
                break;
            case 7:
                printf("Valor: ");
                scanf("%d", &val);
                if (removerValor(&listaDois, val)) {
                    printf("Valor removido.\n");
                } else {
                    printf("Falha ao remover.\n");
                }
                break;
            case 8:
                printf("Valor: ");
                scanf("%d", &val);
                if (busca(&listaDois, val)) {
                    printf("Valor encontrado.\n");
                } else {
                    printf("Valor nao encontrado.\n");
                }
                break;
            case 9:
                if (verificarIntegridade(&listaDois)) {
                    printf("Lista correta.\n");
                } else {
                    printf("Lista incorreta ou vazia.\n");
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