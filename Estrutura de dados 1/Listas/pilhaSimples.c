#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct pilha {
    int pilha[TAM];
    int topo;
} Pilha;

int push(Pilha *p1, int valor) {
    if (p1->topo == TAM) {
        printf("Lista cheia.\n");
        return 0;
    }

    p1->pilha[(p1->topo)++] = valor;
    return 1;
}

int pop(Pilha *p1) {
    if (p1->topo == 0) {
        printf("Lista vazia.\n");
        return 0;
    }

    (p1->topo)--;
    return 1;
}

void top(Pilha *p1) {
    if (p1->topo  == 0) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Valor do topo: %d\n", p1->pilha[p1->topo - 1]);
    printf("Indice do topo: %d\n", (p1->topo - 1));
}

int menu(Pilha p1) {
    system("clear");

    if (p1.topo  == 0) {
        printf("Lista vazia.\n");
    } else {
        printf("Lista: ");
        for (int i = 0; i < p1.topo; i++) 
            printf("%d ", p1.pilha[i]);
        printf("\n");
        top(&p1);
    }

    printf("\n[1]: push.\n");
    printf("[2]: pop.\n");
    printf("[0]: sair.\n");
    printf("Digite a opcao: ");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

int main() {
    Pilha p1;
    p1.topo = 0;
    int valor;

    while (1) {
        switch (menu(p1)) {
            case 0:
                return 0;
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (push(&p1, valor)) {
                    printf("Valor inserido.");
                }

                getchar();
                break;
            case 2:
                if (pop(&p1)) {
                    printf("Valor removido.");
                }
                getchar();
                break;
            case 3:
                (top(&p1));
                getchar();
                break;
        }

        getchar();
    }

    return 0;
}