#include <stdio.h>

// Tudo que for colocado depois da chamada recursiva, será executado na "volta".
void mostrarVetor(int vet[], int tam) {
    if (tam <= 0) 
        return;
    mostrarVetor(vet, tam - 1);
    printf("%i\n", vet[tam - 1]);
}

void lerVetor(int vet[], int tam) {
    if (tam <= 0) 
        return;
    lerVetor(vet, tam - 1);
    scanf("%i", &vet[tam - 1]);
}

int somaVetor(int vet[], int tam) {
    if (tam <= 0)
        return 0;
    return vet[tam - 1] + somaVetor(vet, tam - 1);
}

void troca(int *esquerda, int *direita) {
    int aux = *direita;
    *direita = *esquerda;
    *esquerda = aux;
}

int inverterVetorRec(int vet[], int esquerda, int direita) {
    if (direita <= esquerda) 
        return 0;

    troca(&vet[esquerda], &vet[direita]);

    return inverterVetorRec(vet, esquerda + 1, direita - 1);
}

int inverterVetor(int vet[], int tam) {
    return inverterVetorRec(vet, 0, tam - 1);
}

int main() {
    int vet[5] = {1, 2, 3, 4, 5};
    
    lerVetor(vet, 5);
    mostrarVetor(vet, 5);
    printf("%i\n", somaVetor(vet, 5));
    inverterVetor(vet, 5);
    mostrarVetor(vet, 5);

    return 0;
}