#include <stdio.h>

int verificar(int sequencia[], int A, int sub[], int B){
    int cond = 0;
    for (int i = 0; i < A; i++) {
        if (cond < B && sequencia[i] == sub[cond]) cond++;

        if (cond == B) return 1;
    }
    return 0;
}

void ler(int sequencia[], int tam){
    for (int i = 0; i < tam; i++){
        scanf("%d", &sequencia[i]);
    }
}

int main(){
    int A, B;
    scanf("%d%d", &A, &B);
    int sequencia[A];
    int sub[B];

    ler(sequencia, A);
    ler(sub, B);

    verificar(sequencia, A, sub, B) ? printf("S\n"): printf("N\n");

    return 0;
}