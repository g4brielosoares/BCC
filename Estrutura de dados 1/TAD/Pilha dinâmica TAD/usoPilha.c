#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int menu(){
    int opc;
    system("clear");
    printf("[0] - Sair.\n");
    printf("[1] - Empilhar.\n");
    printf("[2] - Desempilhar.\n");
    printf("[3] - Consultar o topo.\n\n");
    printf("[4] - Mostrar a pilha.\n\n");
    printf("Escolha uma opção: ");
    scanf("%i", &opc);
    return opc;
}

int main()
{
    Pilha *p;
    int vlr, opc, *aux;
    
    p = criar_pilha();
    
    while(opc = menu()){
        switch(opc){
            case 1:
                printf("valor: ");
                scanf("%i", &vlr);
                if (empilhar(p, vlr)){
                    printf("%i empilhado.\n", vlr);
                }else{
                    printf("falha ao empilhar.\n");
                }
                break;
            case 2:
                if (desempilhar(p)){
                    printf("elemento desempilhado.\n");
                }else{
                    printf("pilha vazia.\n");
                }
                break;
            case 3:
                aux = topo(p);
                if (aux == NULL)
                    printf("Pilha vazia");
                else
                    printf("Topo: %i\n", *aux);
                break;
            case 4:
                mostrar_pilha(p);
                break;
        }
        getchar();
        getchar();
    }
    destruir_pilha(&p);
}



