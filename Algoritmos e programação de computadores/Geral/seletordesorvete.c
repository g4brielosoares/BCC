#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int tamanho = 0, sabor = 0, cobertura = 0;
  char valor_tamanho[10] = {"\0"}, valor_sabor[15] = {"\0"}, valor_cobertura[15] = {"\0"};

  system("cls");

  //tamanho
  printf("-SELETOR DE SORVETE-\nSELECIONE O TAMANHO DESEJADO\n[1] 250ml\n[2] 500ml\n[3] 750ml\n = ");
  scanf("%d", &tamanho);
  if (tamanho == 1) {
    strcat(valor_tamanho, "250ml");
  } else if (tamanho == 2) {
    strcat(valor_tamanho, "500ml");
  } else if (tamanho == 3) {
    strcat(valor_tamanho, "750ml");
  }
  system("cls");

  //sabor
  printf("-SELETOR DE SORVETE-\nSELECIONE O SABOR DESEJADO\n[1] CHOCOLATE\n[2] BAUNILHA\n[3] MORANGO\n = ");
  scanf("%d", &sabor);
  if (sabor == 1) {
    strcat(valor_sabor, "chocolate");
  } else if (sabor == 2) {
    strcat(valor_sabor, "baunilha");
  } else if (sabor == 3) {
    strcat(valor_sabor, "morango");
  }
  system("cls");

  //cobertura
  printf("-SELETOR DE SORVETE-\nSELECIONE A COBERTURA DESEJADA\n[1] CHOCOLATE\n[2] CARAMELO\n[3] MORANGO\n = ");
  scanf("%d", &cobertura);
  if (cobertura == 1) {
    strcat(valor_cobertura, "chocolate");
  } else if (tamanho == 2) {
    strcat(valor_cobertura, "caramelo");
  } else if (cobertura == 3) {
    strcat(valor_cobertura, "morango");
  }
  system("cls");

   //resposta
  printf("Voce pediu um sorvete de %s, com sabor de %s e cobertura de %s\n\n", valor_tamanho, valor_sabor, valor_cobertura);
  printf("OBRIGADO POR COMPRAR CONOSCO\n");

  return 0;
}