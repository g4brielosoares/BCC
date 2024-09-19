#include <stdio.h>
#include <stdlib.h>
int main() {
  float num, peso, quant, mult, somap, result, valinseridos;

  printf("Deseja fazer a media de quantos valores? ");
  scanf("%f", &quant);
  
  for(int i = 0; i < quant; i++) {
    printf("\nQUANTIDADE DE VALORES INSERIDOS = %.0f\n", valinseridos);
    printf("Digite o %do valor: ", i + 1);
    scanf("%f", &num);
    printf("Digite um peso para esse valor: ");
    scanf("%f", &peso);

    mult = mult + num * peso;
    somap = somap + peso;
    valinseridos++;
  }

  result = mult / somap;

  printf("\nTOTAL DE VALORES INSERIDOS = %.0f\n", valinseridos);
  printf("O resultado e = %.1f\n", result);

  return 0;
}