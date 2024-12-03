#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

#define TAM 100

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int menu() {
    int opc;

    system(CLEAR);
    printf("[1] - Criar vetor\n");
    printf("[2] - Remover vetor\n");
    printf("[3] - Setar vetor\n");
    printf("[4] - Obter vetor\n");
    printf("[5] - Somar vetores\n");
    printf("[6] - Subtrair vetores\n");
    printf("[7] - Produto escalar\n");
    printf("[8] - Produto vetor por escalar\n");
    printf("[9] - Mostrar vetor\n");
    printf("[0] - Sair\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &opc);

    return opc;
}

int main() {
    int a, b, i, j, k, opc = 0, ultimo = 0;
    Vetor *vetores[TAM];

    while (1) {
        switch (menu()) {
            case 0:
                return 0;
            case 1: 
                printf("Coordenadas do vetor: ");
                scanf("%d %d", &a, &b);

                vetores[ultimo++] = criar_vetor(a, b);

                break;
            case 2:
                printf("Indice do vetor: ");
                scanf("%d", &i);
                remover_vetor(&vetores[i]);

                for (int i = a; i < ultimo; ++i)
                    vetores[i] = vetores[i + 1];

                vetores[ultimo] = NULL;
                ultimo--;

                break;
            case 3: 
                printf("Indice e coordenadas: ");
                scanf("%d %d %d", &i, &a, &b);

                setar_vetor(vetores[i], a, b);

                break;
            case 4: 
                printf("Indice do vetor: ");
                scanf("%d", &i);

                obter_vetor(vetores[i], &a, &b);

                printf("(a: %d, b: %d)\n", a, b);

                break;
            case 5: 
                printf("Indice dos vetores: ");
                scanf("%d %d", &i, &j);

                mostrar_vetor(somar_vetores(vetores[i], vetores[j]));

                break;
            case 6:
                printf("Indice dos vetores: ");
                scanf("%d %d", &i, &j);

                mostrar_vetor(subtrair_vetores(vetores[i], vetores[j]));

                break;
            case 7:
                printf("Indice dos vetores: ");
                scanf("%d %d", &i, &j);

                printf("%d\n", produto_escalar(vetores[i], vetores[j]));

                break;
            case 8:
                printf("Indice do vetor e fator: ");
                scanf("%d %d", &i, &k);

                produto_escalar_por_vetor(vetores[i], k);
                mostrar_vetor(vetores[i]);

                break;
            case 9: 
                for (int i = 0; i < ultimo; ++i) {
                    printf("[%d] - ", i);
                    mostrar_vetor(vetores[i]);
                }

                break;
            default:
                printf("Opcao invalida\n");

                break;
        }
        getchar();
        getchar();
    }

    for (int i = 0; i < ultimo; ++i)
    remover_vetor(&vetores[i]);
}