#include <stdio.h>

int vertices, arestas;

void matrizAdj(int matriz[][vertices]) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void matrizInc(int matriz[][arestas]) {
    for (int i = 0; i < arestas; i++) {
        for (int j = 0; j < arestas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void printMatrizAdj(int matriz[vertices][vertices]) {
    printf("Matriz de adjacencia: \n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void printMatrizInc(int matriz[][arestas]) {
    printf("Matriz de incidencia: \n");
    for (int i = 0; i < arestas; i++) {
        for (int j = 0; j < arestas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    scanf("%d", &vertices);
    scanf("%d", &arestas);

    int a[vertices][vertices], i[vertices][arestas];

    matrizAdj(vertices, a);
    printMatrizAdj(vertices, a);



    return 0;
}