#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *prox;
} Node;

int push(Node **p1, int dado) {
    Node *novo = malloc(sizeof(Node));

    if (!novo) return 0;

    novo->prox = NULL;
    novo->dado = dado;

    if (*p1 == NULL) {
        *p1 = novo;
    } else {
        novo->prox = *p1;
        *p1 = novo;
    }

    return 1;
}

int pop(Node **p1) {
    if (*p1 == NULL) return 0;

    Node *aux = *p1;
    if ((*p1)->prox == NULL) {
        *p1 = NULL;
    } else {
        *p1 = aux->prox;
    }
    
    free(aux);
    return 1;
}

// erro aqui
int *top(Node **p1) {
    if (*p1) {
        return &(*p1)->dado;
    } else {
        return NULL;
    }
}

void print(Node **p1) {
    if (*p1) {
        for (Node *aux = *p1; aux != NULL; aux = aux->prox)
            printf("%d ", aux->dado);
        printf("\n");
    } else {
        printf("Pilha vazia.\n");
    }
}

int menu(Node *p1) {
    int opc;
    system("clear");
    printf("----> ");
	print(&p1);
    printf("\n[1] - Push.\n");
    printf("[2] - Pop.\n");
    printf("[3] - Top.\n");
    printf("[0] - Sair.\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    Node *p1 = NULL;
    int dado, *topo;

    while(1) {
        switch(menu(p1)) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &dado);

                if (push(&p1, dado))
                    printf("Valor inserido.\n");
                else
                    printf("Falha ao inserir.\n");

                break;
            case 2:
                if (pop(&p1)) 
                    printf("Valor removido.\n");
                else
                    printf("Falha ao remover.\n");

                getchar();
                break;
            case 3:
                topo = top(&p1);
                // erro aqui
                if (topo)
                    printf("%ls", topo);
                else
                    printf("Pilha vazia.");

                break;
            case 0:
                return 0;
            default:
                printf("Opcao invalida.\n");

                break;
        }

        getchar();
        getchar();
    }

    return 0;
}