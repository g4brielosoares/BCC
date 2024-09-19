#include <stdio.h>

int main(){
    int N, maior_num = 0, posicao_mn, i = 0;

    while(i < 100){
        scanf("%d", &N);

        if(N > 0 && N > maior_num){
            maior_num = N;
            posicao_mn = i + 1;
        }
        i++;
    }

    printf("%d\n", maior_num);
    printf("%d\n", posicao_mn);

    return 0;
}