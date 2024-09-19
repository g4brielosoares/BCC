#include <stdio.h>
int tamanho;

int main(){
    scanf("%d", &tamanho);
    int V[tamanho], menor_valor = 10000000, posicao = 0;

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &V[i]);
        
        if(V[i] < menor_valor){
            menor_valor = V[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\nPosicao: %d\n", menor_valor, posicao);

    return 0;
}