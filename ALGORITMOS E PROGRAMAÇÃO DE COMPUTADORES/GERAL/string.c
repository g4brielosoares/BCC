#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    system("cls");
    char primeiro_nome[20], sobrenome[20], nome_social[20];
    printf("Escreva seu nome: ");
    fgets(primeiro_nome, 20, stdin);
    printf("Escreva seu sobrenome: ");
    fgets(sobrenome, 20, stdin);
    strcpy(nome_social, primeiro_nome);
    system("cls");
    printf("Te chamarei de %s", nome_social);
    printf("Seu nome completo e %s", strcat(primeiro_nome, sobrenome));
    printf("Te chamarei de %s", nome_social);
    printf("O nome %s tem %d letras", primeiro_nome, strlen(primeiro_nome)-1);
    return 0;
}