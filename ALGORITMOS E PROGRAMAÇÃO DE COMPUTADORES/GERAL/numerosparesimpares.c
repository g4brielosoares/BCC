#include <stdio.h>
#include <stdlib.h>
int main () {
  int numero;
  system("cls");
  printf("Digite o numero desejado: ");
  scanf("%d", &numero);
  if (numero % 2 == 0) {
    printf("%d e par", numero);
  } else {
    printf("%d e impar", numero);
  }
  return 0;
}