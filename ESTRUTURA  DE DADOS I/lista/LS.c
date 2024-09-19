#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct lista {
	int vet[TAM];
	int qtd;
} Lista;

void deslocarDireita(Lista *lista, int indice) {
    if (indice == 0) {
        for(int i = lista->qtd; i > 0; i--) {
		    lista->vet[i] = lista->vet[i - 1];
	    }
    } else {
        for(int i = lista->qtd; i > indice; i--) {
            lista->vet[i] = lista->vet[i - 1];
        }
    }
}

void deslocarEsquerda(Lista *lista) {
	for(int i = 0; i < lista->qtd; i++) {
		lista->vet[i] = lista->vet[i + 1];
	}
}

int inserirNoInicio(Lista *lista, int num, int indice) {
	if(lista->qtd >= TAM) {
		return 0;
	}

	deslocarDireita(lista, indice);
	lista->vet[0] = num;
	lista->qtd++;

	return 1;
}

int inserirNoFinal(Lista *lista, int num) {
	if(lista->qtd >= TAM) {
		return 0;
	}
	
	lista->vet[lista->qtd] = num;
	lista->qtd++;

	return 1;
}

int inserirNoMeio(Lista *lista, int num, int indice) {
    if(lista->qtd >= TAM) {
		return 0;
	}

    deslocarDireita(lista, indice);
    lista->vet[indice] = num;
    lista->qtd++;

    return 1;
}

void removerNoFinal(Lista *lista) {
	if(lista->qtd > 0) {
		lista->qtd--;
	}
}

void removerNoInicio(Lista *lista) {
	if(lista->qtd >= 0) {
	    lista->qtd--;
		deslocarEsquerda(lista);
	}
}

void mostrarLista(Lista *lista) {
	for(int i = 0; i < lista->qtd; i++) {
		printf("%d ", lista->vet[i]);
	}
	printf("\n");
}

int menu(Lista lista) {
    int opc;
    system("clear");
	printf("----> ");
	mostrarLista(&lista);
    printf("[1] - Incluir no inicio.\n");
    printf("[2] - Incluir no meio.\n");
    printf("[3] - Incluir no final.\n");
    printf("[4] - Remover do inicio.\n");
    printf("[5] - Remover do meio.\n");
    printf("[6] - Remover do final.\n");
	printf("[0] - Sair.\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
	Lista A;
	A.qtd = 0;
	int val, indice = 0;
	
	while (1) {
    	switch (menu(A)) {
			case 0:
				return 0;
				break;
    	    case 1:
    	        printf("valor: ");
    	        scanf("%d", &val);
    	        if (inserirNoInicio(&A, val, indice)) {
    	            printf("Inserido\n");
    	        } else {
    	            printf("Nao inserido\n");
    	        }
                indice = 0;
    	        break;
    	    case 2:

                break;
            case 3:
    	        printf("valor: ");
    	        scanf("%d", &val);
    	        if (inserirNoFinal(&A, val)) {
    	            printf("Inserido\n");
    	        } else {
    	            printf("Nao inserido\n");
    	        }
    	        break;
    	    case 4:
                printf("Valor: ");
                scanf("%d", &val);
                printf("indice: ");
                scanf("%d", &indice);
                if (inserirNoMeio(&A, val, indice)) {
    	            printf("Inserido\n");
    	        } else {
    	            printf("Nao inserido\n");
    	        }
                indice = 0;
    	        break;
    	    case 5:
    	        removerNoInicio(&A);
				break;
			case 6:
    	        removerNoFinal(&A);
    	        break;
			default:
                printf("Opcao invalida.");
				break;
    	}
    	getchar();
    	getchar();
	}

	return 0;
}