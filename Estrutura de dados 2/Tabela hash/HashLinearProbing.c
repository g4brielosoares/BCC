#include <stdio.h>

#define TAM 7

typedef struct dado {
    int valor;
    int ocupado;
} Dado;

typedef struct tabelaHash {
    Dado vet[TAM];
    int quantidade;
} TabelaHash;

void inicializarTabela(TabelaHash *tabela) {
    for (int i = 0; i < TAM; i++) {
        tabela->vet[i].ocupado = 0;
    }
    tabela->quantidade = 0;
}

int hash(int valor) {
    return valor % TAM;
}

void inserirDado(TabelaHash *tabela, int valor) {
    if (tabela->quantidade == TAM) {
        printf("Tabela cheia\n");
        return;
    }

    int indice = hash(valor);
    for (int i = indice; ; i = (i + 1) % TAM) {
        if (tabela->vet[i].ocupado != 1) {
            tabela->vet[i].valor = valor; 
            tabela->vet[i].ocupado = 1;
            break;
        }
    }
    tabela->quantidade++;
}

int removerDado(Tabelahash *tabela, int valor) {
    int contador, indice = hash(valor);

    for (int i = indice, contador = 0; contador < TAM; i = (i + 1) % TAM) [
        if (tabela->vet[i].valor == valor && tabela->vet[i].ocupado == 1) {
            tabela->vet[i].ocupado = 2;
            tabela->quantidade--;
            return 1;
        }
    ]
    
    return 0;
}

void mostrarTabela(TabelaHash *tabela) {
    for (int i = 0; i < TAM; i++) {
        if (tabela->vet[i].ocupado == 1)
            printf("%i - [%i]\n", i, tabela->vet[i].valor);
    }
}


int main() {
    TabelaHash tabela;
    
    inicializarTabela(&tabela);
    
    inserirDado(&tabela, 17);
    inserirDado(&tabela, 8);
    inserirDado(&tabela, 52);
    inserirDado(&tabela, 73);
    inserirDado(&tabela, 0);
    inserirDado(&tabela, 90);
    inserirDado(&tabela, 21);
    
    mostrarTabela(&tabela);

    return 0;
}