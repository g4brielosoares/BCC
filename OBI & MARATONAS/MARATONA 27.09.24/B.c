#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int tipos[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &tipos[i]);
    }

    int qtdInstituicoes;
    scanf("%d", &qtdInstituicoes);
    int num;
    int maior = 0;
    int result[qtdInstituicoes];

    for(int i = 0; i < qtdInstituicoes; i++){
        maior = 0;
        scanf("%d", &num);
        for(int i = 0; i < n ;i++){
            if(tipos[i] % num == 0){ 
                if(tipos[i] > maior){
                 maior = i;
                } 
            }
        }
        if(maior == 0){
            result[i] = -1;
        } else {
            result[i] = maior +1;
        }
    }
    
    for(int i = 0; i < qtdInstituicoes; i++){
        printf("%d\n", result[i]);
    }

    return 0;
}