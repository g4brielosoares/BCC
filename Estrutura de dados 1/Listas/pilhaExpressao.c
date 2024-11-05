#include <stdio.h>
#include <stdlib.h>

#define TAM 50

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

int checkThePile(Pilha *p1, char caractere) {
    if (caractere == p1->pilha[p1->topo - 1]) {
        pop(p1);
        return 1;
    }

    return 0;
}

int isValid(char string[], Pilha *p1) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '[' || string[i] == '{' || string[i] == '(') 
            push(p1, string[i]);

        if (string[i] == ']')
            if (!checkThePile(p1, '[')) return 0;
        
        if (string[i] == '}')
            if (!checkThePile(p1, '{')) return 0;

        if (string[i] == ')')
            if (!checkThePile(p1, '(')) return 0;
    }

    return 1;
}

int main() {
    Pilha p1;
    p1.topo = 0;
    char str[100];

    fgets(str, 99, stdin);

    if (isValid(str, &p1))
        printf("Is valid.\n");
    else 
        printf("Is not valid.\n");

    return 0;
}