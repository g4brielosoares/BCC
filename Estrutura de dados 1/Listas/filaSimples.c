#include <stdio.h>

#define TAM 5

typedef struct fila {
    int vet[TAM];
    int primeiro;
    int ultimo;
} Fila;

int enfileirar(Fila *f, int val) {
    if ((f->ultimo + 1) % TAM == f->primeiro) return 0;

    f->vet[f->ultimo] = val;
    f->ultimo = (f->ultimo + 1) % TAM;
    return 1;
}

int desenfileirar(Fila *f) {
    if (f->ultimo == f->primeiro) return 0;

    f->primeiro = (f->primeiro + 1) % TAM;
    return 1;
}

void mostrar_lista(Fila *f) {
    if (f->ultimo == f->primeiro) {
        printf("Fila vazia.\n");
    } else {
        for (int i = f->primeiro; i != f->ultimo; i = (i + 1) % TAM) 
            printf("%d ", f->vet[i]);
        printf("\n");
    }
}

int *primeiro(Fila *f) {
    if (f->primeiro == f->ultimo) 
        return NULL;

    return  &f->vet[f->primeiro];
} 

int main() {
    Fila f;
    int *aux;

    f.primeiro = 0;
    f.ultimo = 0;

    mostrar_lista(&f);

    enfileirar(&f, 3);
    mostrar_lista(&f);

    enfileirar(&f, 2);
    mostrar_lista(&f);

    enfileirar(&f, 1);
    mostrar_lista(&f);

    aux = primeiro(&f);
    if (aux == NULL)
        printf("Fila vazia.\n");
    else 
        printf("Primeiro = %d.\n", *aux);

    enfileirar(&f, 0);
    mostrar_lista(&f);

    desenfileirar(&f);
    mostrar_lista(&f);

    aux = primeiro(&f);
    if (aux == NULL)
        printf("Fila vazia.\n");
    else 
        printf("Primeiro = %d.\n", *aux);

    desenfileirar(&f);
    mostrar_lista(&f);

    desenfileirar(&f);
    mostrar_lista(&f);

    desenfileirar(&f);
    mostrar_lista(&f);


    return 0;
}